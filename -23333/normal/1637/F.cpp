#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll long long
const int N=5e5;
vector<int> ve[N];
int a[N],siz[N],dfn[N],pos[N],b[N],c[N];
int cnt=0;
#define mid ((h+t)/2)
struct sgt{
	int v[N*4];
	void build(int x,int h,int t)
	{
		if (h==t) {v[x]=a[pos[h]]; return;}
		build(x*2,h,mid); build(x*2+1,mid+1,t);
		v[x]=max(v[x*2],v[x*2+1]);
	}
	int q(int x,int h,int t,int h1,int t1)
	{
		if (h1>t1) return 0;
		if (h1<=h&&t<=t1) return v[x];
		int ans=0;
		if (h1<=mid) ans=q(x*2,h,mid,h1,t1);
		if (mid<t1) ans=max(ans,q(x*2+1,mid+1,t,h1,t1));
		return ans;
	}
}S;
ll ans=0;
void dfs(int x,int y)
{
	/*dfn[x]=++cnt; pos[cnt]=x;
	siz[x]=1; b[x]=a[x]; */
	for (auto v:ve[x])
	  if (v!=y)
	  {
	  	dfs(v,x);
	  	if (b[v]>b[x])
	  	{
	  		c[x]=b[x];
	  		b[x]=b[v];
	  	} else
	  	if (b[v]>c[x])
	  	{
	  		c[x]=b[v];
	  	}
	  }
	if (!y)
	{
		ans+=max(0,a[x]-b[x])+max(0,a[x]-c[x]);
	} else
	{
		ans+=max(0,a[x]-b[x]);
		b[x]=max(a[x],b[x]);
	}
}
int main()
{
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	int now=0;
	rep(i,1,n) if (a[i]>=a[now]) now=i;
	dfs(now,0);
    cout<<ans<<endl;
    return 0; 
}