#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

vector<int> G[300005];
int dp[300005],sdp[300005],ans=0;

void dfs(int u,int f)
{
	dp[u]=1+SZ(G[u]),sdp[u]=0;
	for(int i:G[u])
		if(i!=f)
		{
			dfs(i,u);
			int tmp=dp[i]-1+SZ(G[u]);
			if(tmp>dp[u]) sdp[u]=dp[u],dp[u]=tmp;
			else if(tmp>sdp[u]) sdp[u]=tmp;
		}
}

void dfs2(int u,int f,int x)
{
	x+=SZ(G[u])+1-(u!=1);
	if(x>dp[u]) sdp[u]=dp[u],dp[u]=x;
	else if(x>sdp[u]) sdp[u]=x;
	ans=max(ans,dp[u]);
	for(int i:G[u])
		if(i!=f)
			if(dp[u]==dp[i]-1+SZ(G[u])) dfs2(i,u,sdp[u]-1);
			else dfs2(i,u,dp[u]-1);
}

int main()
{
	IOS();
	int q,n,a,b;
	cin >> q;
	while(q--)
	{
		cin >> n,ans=0;
		for(int i=1;i<=n;++i)
			G[i].clear();
		for(int i=1;i<n;++i)
			cin >> a >> b,G[a].pb(b),G[b].pb(a);
		dfs(1,1),dfs2(1,1,0);
		cout << ans << "\n";
	}
}