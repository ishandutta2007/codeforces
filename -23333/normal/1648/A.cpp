#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
vector<int> ve[N];
ll sum[N],cnt[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	//cin>>T;
	T=1;
	while (T--)
	{ 
	  int n,m;
	  cin>>n>>m;
	  rep(i,1,n)
	  {
	  	ve[i].push_back(0);
	  	rep(j,1,m)
	  	{
	  		int x;
	  	  cin>>x;
	  	  ve[i].push_back(x);
	    }
	  }
	  ll ans=0;
	  rep(j,1,m)
	    rep(i,1,n)
	    {
	    	ans+=j*cnt[ve[i][j]]-sum[ve[i][j]];
	    	sum[ve[i][j]]+=j; cnt[ve[i][j]]++;
	    }
	  rep(i,1,1e5) sum[i]=cnt[i]=0;
	  rep(i,1,n)
	    rep(j,1,m)
	    {
	    	ans+=i*cnt[ve[i][j]]-sum[ve[i][j]];
	    	sum[ve[i][j]]+=i; cnt[ve[i][j]]++;
	    }
	  cout<<ans<<endl;
    }
	return 0;
}