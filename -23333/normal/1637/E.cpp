#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3.1e5;
int a[N],n,m;
map<int,int> M;
map<pair<int,int>,int> M2;
vector<int> ve[N];
vector<int> g;
signed main()
{
//	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		n=3e5,m=0;
		cin>>n>>m;
		M.clear(); M2.clear(); g.clear();
		rep(i,1,n)
		{ 
		  a[i]=i;
		  cin>>a[i];
		  M[a[i]]++;
	    }
	    rep(i,1,m)
	    {
	    	int x,y;
	    	cin>>x>>y;
	    	M2[{x,y}]=M2[{y,x}]=1;
	    }
	    for (auto v:M)
	    {
	    	ve[v.second].push_back(v.first);
	    	g.push_back(v.second);
	    }
	    sort(g.begin(),g.end());
	    g.erase(unique(g.begin(),g.end()),g.end());
	    assert(g.size()<=2*sqrt(n)+3);
	    for (auto v:g)
	    {
	    	sort(ve[v].begin(),ve[v].end());
	    	reverse(ve[v].begin(),ve[v].end());
	    }
	    ll ans=0;
	    int cnt3=0;
	    for (auto v1:g)
	      for (auto v2:g)
	        if (v1>=v2)
	        {
	        	for (auto v3:ve[v1])
	        	  for (auto v4:ve[v2])
	        	    if (v3!=v4&&M2.find({v3,v4})==M2.end())
					{
					  cnt3++; 
					  ans=max(ans,1ll*(v1+v2)*(v3+v4));
					  break;
				    }
	        }
	    cout<<ans<<endl;
	    for (auto v:g) ve[v].clear();
	}
	return 0; 
}