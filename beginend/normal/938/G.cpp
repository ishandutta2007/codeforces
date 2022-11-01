#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;

const int N=200005;

typedef pair<int,int> pi;

int n,m,val[N],f[N],size[N],stack[N],top,bas[35][35],bin[35],cnt,tot;
pi qu[N];
struct edge{int u,v,w,s,t;}e[N*2];
map<pi,int> ma;
vector<int> vec[N*4];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int find(int x)
{
	while (f[x]!=x) x=f[x];
	return x;
}

int get_val(int x)
{
	int w=0;
	while (f[x]!=x) w^=val[x],x=f[x];
	return w;
}

void add(int d,int dep)
{
	for (int i=0;i<vec[d].size();i++)
	{
		int id=vec[d][i],u=e[id].u,v=e[id].v,x=find(u),y=find(v);
		if (x!=y)
		{
			if (size[x]>size[y]) swap(u,v),swap(x,y);
			f[x]=y;size[y]+=size[x];val[x]=get_val(u)^get_val(v)^e[id].w;stack[++top]=x;
		}
		else
		{
			int w=get_val(u)^get_val(v)^e[id].w;
			for (int i=30;i>=0;i--)
				if (w&bin[i])
				{
					if (!bas[dep][i]) {bas[dep][i]=w;break;}
					else w^=bas[dep][i];
				}
		}
	}
}

void del(int tmp)
{
	while (top>tmp)
	{
		int x=stack[top];top--;
		size[f[x]]-=size[x];f[x]=x;val[x]=0;
	}
}

void ins(int d,int l,int r,int x,int y,int id)
{
	if (x>y) return;
	if (l==x&&r==y) {vec[d].pb(id);return;}
	int mid=(l+r)/2;
	if (y<=mid) ins(d*2,l,mid,x,y,id);
	else if (x>mid) ins(d*2+1,mid+1,r,x,y,id);
	else ins(d*2,l,mid,x,mid,id),ins(d*2+1,mid+1,r,mid+1,y,id);
}

void solve(int d,int l,int r,int dep)
{
	int tmp=top;add(d,dep);
	if (l==r)
	{
		int x=qu[l].first,y=qu[l].second,w=get_val(x)^get_val(y);
		for (int i=30;i>=0;i--) if ((w^bas[dep][i])<w) w^=bas[dep][i];
		printf("%d\n",w);del(tmp);
		return;
	}
	int mid=(l+r)/2;
	for (int i=0;i<=30;i++) bas[dep+1][i]=bas[dep][i];
	solve(d*2,l,mid,dep+1);
	for (int i=0;i<=30;i++) bas[dep+1][i]=bas[dep][i];
	solve(d*2+1,mid+1,r,dep+1);
	del(tmp);
}

int main()
{
	//freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	bin[0]=1;
	for (int i=1;i<=30;i++) bin[i]=bin[i-1]*2;
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		e[++cnt].u=x;e[cnt].v=y;e[cnt].w=z;
		ma[mp(x,y)]=cnt;e[cnt].s=1;e[cnt].t=-1;
	}
	int q=read();
	for (int i=1;i<=q;i++)
	{
		int op=read(),x=read(),y=read();
		if (op==1)
		{
			int d=read();
			e[++cnt].u=x;e[cnt].v=y;e[cnt].w=d;
			ma[mp(x,y)]=cnt;e[cnt].s=tot+1;e[cnt].t=-1;
		}
		else if (op==2) e[ma[mp(x,y)]].t=tot,ma[mp(x,y)]=0;
		else qu[++tot]=mp(x,y);
	}
	for (int i=1;i<=cnt;i++) ins(1,1,tot,e[i].s,e[i].t==-1?tot:e[i].t,i);
	for (int i=1;i<=n;i++) f[i]=i,size[i]=1;
	solve(1,1,tot,0);
	return 0;
}