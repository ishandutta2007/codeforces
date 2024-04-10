#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=7e5;
struct re{
	int a,b,c;
}a[N];
int n,fa[N],ls[N],rs[N],bz[N][20],dfn[N],pos[N],dep[N],cnt;
bool cmp(re x,re y)
{
	return x.c<y.c;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]); 
} 
void dfs(int x,int y)
{
	bz[x][0]=y; dep[x]=dep[y]+1;
	rep(i,1,19) bz[x][i]=bz[bz[x][i-1]][i-1];
	dfn[x]=++cnt; pos[dfn[x]]=x;
	if (ls[x]) dfs(ls[x],x);
	if (rs[x]) dfs(rs[x],x);
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	dep(i,19,0) if (dep[bz[x][i]]>=dep[y]) x=bz[x][i];
	if (x==y) return x;
	dep(i,19,0) if (bz[x][i]!=bz[y][i]) x=bz[x][i],y=bz[y][i];
	return bz[x][0]; 
}
#define mid ((h+t)/2) 
struct sgt{
	int mn[N*4],mx[N*4],lazy[N*4],vmn[N*4],vmx[N*4]; 
	void build(int x,int h,int t)
	{
		vmn[x]=1.1e9; vmx[x]=0;
		if (h==t)
		{
			mn[x]=mx[x]=dfn[h]; return;
		}
	    build(x*2,h,mid); build(x*2+1,mid+1,t);
	    mn[x]=min(mn[x*2],mn[x*2+1]);
		mx[x]=max(mx[x*2],mx[x*2+1]); 
	}
	void gao(int x,int y)
	{
		if (y==1)
		{
			vmn[x]=mn[x]; vmx[x]=mx[x]; lazy[x]=1; 
		} else
		{
			vmn[x]=1.1e9; vmx[x]=0; lazy[x]=2;
		}
	}
	inline void down(int x)
	{
		if (lazy[x])
		{
			gao(x*2,lazy[x]);
			gao(x*2+1,lazy[x]);
			lazy[x]=0;
		}
	}
	void g(int x,int h,int t,int h1,int t1,int k)
	{
		if (h1<=h&&t<=t1)
		{
			gao(x,k); return;
		}
		down(x);
		if (h1<=mid) g(x*2,h,mid,h1,t1,k);
		if (mid<t1) g(x*2+1,mid+1,t,h1,t1,k);
		vmn[x]=min(vmn[x*2],vmn[x*2+1]);
		vmx[x]=max(vmx[x*2],vmx[x*2+1]);
	}
}S;
int js(int x,int y)
{
	if (x==y) return -1;
	return a[lca(x,y)-n].c;
}
int main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>n>>q;
	rep(i,1,n-1)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a+1,a+n,cmp);
	rep(i,1,2*n) fa[i]=i;
	rep(i,1,n-1)
	{
		int x=find(a[i].a),y=find(a[i].b);
		ls[n+i]=x; rs[n+i]=y; 
		fa[x]=fa[y]=n+i;
	}
	dfs(n+n-1,0);
	S.build(1,1,n);
	while (q--)
	{
		int tt,k,x,y;
		cin>>tt;
		if (tt==3)
		{
			cin>>k;
			if (S.vmn[1]==1.1e9)
			{
				cout<<-1<<endl;
			} else
			{
				cout<<max(js(pos[S.vmn[1]],k),js(pos[S.vmx[1]],k))<<endl;
			}
		} else
		{
			cin>>x>>y;
			S.g(1,1,n,x,y,tt);
		}
	}
	return 0; 
}