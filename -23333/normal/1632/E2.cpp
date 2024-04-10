#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
const int N=5e5;
vector<int> ve[N];
int dep[N],fa[N],nowans=0,jl=0;
int pre[N],suf[N],b[N],e[N],n,m;
vector<int> g;
void dfs(int x,int y)
{
	dep[x]=dep[y]+1; fa[x]=y;
	if (dep[x]>nowans)
	{
		nowans=dep[x]; jl=x;
	}
	for (auto v:ve[x])
	  if (v!=y)
	    dfs(v,x);
}
int dfs2(int x,int y)
{
	int ans=0;
	for (auto v:ve[x])
	  if (v!=y&&v!=fa[x])
	  {
	  		ans=max(ans,dfs2(v,x));
	  }
	return ans+1;
}
#define mid ((h+t)/2)
struct sgt{
	int v[N*4];
	sgt()
	{
		rep(i,0,N*4-1) v[i]=-1e9;
	}
	void clear(int x)
	{
		rep(i,0,x*4) v[i]=-1e9;
	}
	void build(int x,int h,int t)
	{
		if (h==t)
		{
			v[x]=e[h]; return;
		}
		build(x*2,h,mid); build(x*2+1,mid+1,t);
		v[x]=max(v[x*2],v[x*2+1]);
	}
	int q(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v[x];
		int ans=-1e9;
		if (h1<=mid) ans=q(x*2,h,mid,h1,t1);
		if (mid<t1) ans=max(ans,q(x*2+1,mid+1,t,h1,t1));
		return ans;
	}
}S;
int check(int x,int y)
{
	int pos=(x+y)/2;
	pos=min(m,min(pos,x));
	int ans=pre[pos];
	if (x<=m)
	{
		ans=max(ans,suf[x]-x+y);
		if (pos+1<=x)
		{
			ans=max(ans,y+x+S.q(1,1,m,pos+1,x));
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	dep[0]=-1;
	int pdd=T,cnt=0;
	while (T--)
	{
		cin>>n;
		cnt+=n;
		nowans=0,jl=0;
	//	cout<<n<<endl;
		rep(i,1,n-1) 
		{
			int x,y;
			cin>>x>>y;
			// cout<<x<<" "<<y<<endl;
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		dfs(1,0);
		g.clear();
		while (jl)
		{
			if (fa[jl]) b[fa[jl]]=dfs2(fa[jl],jl)-1;
			g.push_back(jl); jl=fa[jl];
	    }
		g.push_back(0);
	    m=g.size()-1;
	    reverse(g.begin(),g.end());
	    rep(i,1,m)
	      pre[i]=max(pre[i-1],b[g[i]]+i-1);
	    suf[m+1]=0;
	    dep(i,m,1)
		  suf[i]=max(suf[i+1],b[g[i]]+i);
		rep(i,1,m) e[i]=b[g[i]]-i;
		S.build(1,1,m);  
		int now=2;
		rep(i,1,n)
		{
			int lst=now;
			while (now<=m&&check(now,i)>check(now+1,i))
			{
			  if (check(now,i)>check(now+1,i)) lst=now+1; 
			  now++;
		    }
		    now=lst;
			 cout<<check(now,i)<<" ";
	    }
	    cout<<"\n";
	    S.clear(m);
		rep(i,1,n) ve[i].clear(),b[i]=0;
	}
	return 0;
}