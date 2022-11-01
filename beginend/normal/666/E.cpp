#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1100005;

int n,m,sz,cnt,ch[N][26],fa[N],bz[N][21],mx[N],rt[N],id[N],last,ans,pos,b[N],c[N];
char str[N];
struct tree{int l,r,mx,pos;}t[N*30];

int extend(int x)
{
	if (ch[last][x])
	{
		int p=last,q=ch[last][x];
		if (mx[q]==mx[p]+1) return last=q;
		int nq=++cnt;mx[nq]=mx[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[q]));
		fa[nq]=fa[q];fa[q]=nq;
		for (;ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		return last=nq;
	}
	int p,q,np,nq;
	p=last;last=np=++cnt;mx[np]=mx[p]+1;
	for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if (!p) fa[np]=1;
	else
	{
		q=ch[p][x];
		if (mx[q]==mx[p]+1) fa[np]=q;
		else
		{
			nq=++cnt;mx[nq]=mx[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for (;ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		}
	}
	return last;
}

int merge(int x,int y,int l,int r)
{
    if (!x&&!y) return x+y;
    int d=++sz,mid=(l+r)/2;
    if (l==r) {t[d].mx=t[x].mx+t[y].mx;t[d].pos=l;return d;}
    t[d].l=merge(t[x].l,t[y].l,l,mid);
    t[d].r=merge(t[x].r,t[y].r,mid+1,r);
    if (t[t[d].l].mx>=t[t[d].r].mx) t[d].mx=t[t[d].l].mx,t[d].pos=t[t[d].l].pos;
    else t[d].mx=t[t[d].r].mx,t[d].pos=t[t[d].r].pos;
    return d;
}

void ins(int &d,int l,int r,int x)
{
    if (!d) d=++sz;
    if (l==r) {t[d].mx++;t[d].pos=l;return;}
    int mid=(l+r)/2;
    if (x<=mid) ins(t[d].l,l,mid,x);
    else ins(t[d].r,mid+1,r,x);
    if (t[t[d].l].mx>=t[t[d].r].mx) t[d].mx=t[t[d].l].mx,t[d].pos=t[t[d].l].pos;
    else t[d].mx=t[t[d].r].mx,t[d].pos=t[t[d].r].pos;
}

void query(int d,int l,int r,int x,int y)
{
    if (l==x&&r==y)
    {
        if (t[d].mx>ans) ans=t[d].mx,pos=t[d].pos;
        return;
    }
    int mid=(l+r)/2;
    if (y<=mid) query(t[d].l,l,mid,x,y);
    else if (x>mid) query(t[d].r,mid+1,r,x,y);
    else query(t[d].l,l,mid,x,mid),query(t[d].r,mid+1,r,mid+1,y);
}

void prepare()
{
    for (int i=1;i<=cnt;i++) bz[i][0]=fa[i];
    for (int j=1;j<=20;j++)
        for (int i=1;i<=cnt;i++)
            bz[i][j]=bz[bz[i][j-1]][j-1];
    for (int i=1;i<=cnt;i++) b[mx[i]]++;
    for (int i=1;i<=cnt;i++) b[i]+=b[i-1];
    for (int i=cnt;i>=1;i--) c[b[mx[i]]--]=i;
    for (int i=cnt;i>=2;i--) rt[fa[c[i]]]=merge(rt[fa[c[i]]],rt[c[i]],1,m);
}

int main()
{
    scanf("%s",str+1);n=strlen(str+1);
    cnt=last=1;
    for (int i=1;i<=n;i++) id[i]=extend(str[i]-'a');
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%s",str+1);int len=strlen(str+1);last=1;
        for (int j=1,x;j<=len;j++)
            x=extend(str[j]-'a'),ins(rt[x],1,m,i);
    }
    prepare();
    int q;scanf("%d",&q);
    while (q--)
    {
        int l,r,x,y;
        scanf("%d%d%d%d",&l,&r,&x,&y);
        int now=id[y];
        for (int i=20;i>=0;i--)
            if (mx[bz[now][i]]>=y-x+1) now=bz[now][i];
        ans=0;pos=l;
        query(rt[now],1,m,l,r);
        printf("%d %d\n",pos,ans);
    }
    return 0;
}