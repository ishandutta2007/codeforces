#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int n,m;
ll a[N];
struct re{
	int a,b,c;
};
const int mo=998244353;
vector<re> E[N];
vector<int> ve[N];
ll dp[N];
int gg[N],ans[N];
ll anssum=0;
ll fsp(int x,int y)
{
    if (y==0) return 1;
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans%mo;
    if (y%2==1) ans=ans*x%mo;
    return ans;
}
void dfs(int x,int y)
{
	for (auto v:E[x])
	  if (v.a!=y)
	  {
	  	  for (auto vv:ve[v.c]) gg[vv]--;
	  	  for (auto vv:ve[v.b]) gg[vv]++,ans[vv]=max(ans[vv],gg[vv]);
	  	  dfs(v.a,x);
	  	  for (auto vv:ve[v.c]) gg[vv]++;
	  	  for (auto vv:ve[v.b]) gg[vv]--;
	  }
}
void dfs2(int x,int y,ll z)
{
//	cout<<x<<" "<<z<<endl;
	(anssum+=z)%=mo;
	for (auto v:E[x])
	  if (v.a!=y)
 	  {
 	  //	  cerr<<v.b<<" "<<fsp(v.b,mo-2)<<endl;
	  	  dfs2(v.a,x,z*fsp(v.b,mo-2)%mo*v.c%mo);
	  }
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	rep(i,2,2e5)
	{
	  bool tt=1;
	  for(int j=2;j<=sqrt(i);j++)
	    if (i%j==0)
	    {
	    	ve[i].push_back(j);
	    	for (auto v:ve[i/j]) ve[i].push_back(v);
	    	tt=0;
	    	break;
	    }
	  if (tt) { ve[i].push_back(i);}
	  sort(ve[i].begin(),ve[i].end());
    }
	while (T--)
	{
		anssum=0;
		cin>>n;
		rep(i,1,n-1)
		{
			int x,y,a,b;
			cin>>x>>y>>a>>b;
			E[x].push_back({y,a,b});
			E[y].push_back({x,b,a});
		}
		dfs(1,0);
		ll ans2=1;		
		rep(i,2,n)
		  while (ans[i]>0) { ans2=ans2*i%mo,ans[i]--;}
		dfs2(1,0,ans2);
		rep(i,1,n) E[i].clear(),gg[i]=ans[i]=0;
		cout<<(anssum%mo+mo)%mo<<endl;
    }
	return 0;
}