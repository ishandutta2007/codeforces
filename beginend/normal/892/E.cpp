#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

const int N=500005;

int n,m,f[N],a[N];
struct data{int x,y,z;}e[N];
struct tree{int l,r,fa,mx,val;bool rev;}t[N*2];
stack<int> sta;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

bool is_root(int x)
{
    return x!=t[t[x].fa].l&&x!=t[t[x].fa].r||!t[x].fa;
}

void pushdown(int d)
{
    if (!t[d].rev) return;
    swap(t[d].l,t[d].r);t[d].rev^=1;
    if (t[d].l) t[t[d].l].rev^=1;
    if (t[d].r) t[t[d].r].rev^=1;
}

void updata(int x)
{
    t[x].mx=max(t[x].val,max(t[t[x].l].mx,t[t[x].r].mx));
}

void remove(int x)
{
    while (!is_root(x)) sta.push(x),x=t[x].fa;
    sta.push(x);
    while (!sta.empty()) x=sta.top(),sta.pop(),pushdown(x);
}

void rttr(int x)
{
    int y=t[x].l;
    t[x].l=t[y].r;t[t[y].r].fa=x;
    if (x==t[t[x].fa].l) t[t[x].fa].l=y;
    else if (x==t[t[x].fa].r) t[t[x].fa].r=y;
    t[y].fa=t[x].fa;
    t[y].r=x;t[x].fa=y;
    updata(x);updata(y);
}

void rttl(int x)
{
    int y=t[x].r;
    t[x].r=t[y].l;t[t[y].l].fa=x;
    if (x==t[t[x].fa].l) t[t[x].fa].l=y;
    else if (x==t[t[x].fa].r) t[t[x].fa].r=y;
    t[y].fa=t[x].fa;
    t[y].l=x;t[x].fa=y;
    updata(x);updata(y);
}

void splay(int x)
{
    remove(x);
    while (!is_root(x))
    {
        int p=t[x].fa,g=t[p].fa;
        if (is_root(p))
        {
            if (x==t[p].l) rttr(p);
            else rttl(p);
            break;
        }
        if (x==t[p].l)
            if (p==t[g].l) rttr(g),rttr(p);
            else rttr(p),rttl(g);
        else
            if (p==t[g].r) rttl(g),rttl(p);
            else rttl(p),rttr(g);
    }
    updata(x);
}

void access(int x)
{
    int y=0;
    while (x)
    {
        splay(x);t[x].r=y;
        y=x;x=t[x].fa;
    }
}

void make_root(int x)
{
    access(x);splay(x);t[x].rev^=1;
}

void link(int x,int y)
{
    make_root(y);splay(y);t[y].fa=x;
}

void cut(int x,int y)
{
    make_root(x);access(y);splay(y);t[y].l=t[x].fa=0;
}

int query(int x,int y)  
{  
    make_root(x);access(y);splay(y);
    while (t[t[y].l].mx==t[y].mx||t[t[y].r].mx==t[y].mx)  
        if (t[t[y].l].mx>t[t[y].r].mx) y=t[y].l;  
        else y=t[y].r;
    return y;  
}  

int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) f[i]=i;
	t[0].mx=-1;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		e[i].x=x;e[i].y=y;e[i].z=z;t[i+n].val=t[i+n].mx=z;
		if (find(x)!=find(y)) f[find(x)]=find(y),link(x,i+n),link(y,i+n);
		else
		{
			int id=query(x,y);
			if (t[id].val>z) cut(id,e[id-n].x),cut(id,e[id-n].y),link(x,i+n),link(y,i+n);
		}
	}
	int q=read();
	while (q--)
	{
		int k=read();
		for (int i=1;i<=k;i++) a[i]=read();
		int flag=0;
		for (int i=1;i<=k;i++)
		{
			int x=e[a[i]].x,y=e[a[i]].y,z=e[a[i]].z;
			int id=query(x,y);
			if (t[id].val<z) {flag=1;break;}
			cut(id,e[id-n].x);cut(id,e[id-n].y);
			t[a[i]+n].val=0;
			link(a[i]+n,x);link(a[i]+n,y);
		}
		for (int i=1;i<=k;i++) t[a[i]+n].val=e[a[i]].z,splay(a[i]+n);
		if (!flag) puts("YES");
		else puts("NO");
	}
	return 0;
	
}