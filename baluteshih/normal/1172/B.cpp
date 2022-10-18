#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=998244353;
vector<ll> G[200005];
ll dp[200005],w[200005],J[200005];

void dfs(ll u,ll f)
{
	dp[u]=1,w[u]=1;
	for(ll i:G[u])
		if(i!=f)
		{
			dfs(i,u),w[u]+=w[i];
			dp[u]=dp[u]*dp[i]%MOD*(ll)(G[i].size())%MOD;
		}
	if(u!=1) dp[u]=dp[u]*J[G[u].size()-1]%MOD;
	else dp[u]=dp[u]*J[G[u].size()]%MOD;
}

int main()
{jizz
	ll n,a,b;
	cin >> n,J[0]=1;
	for(int i=1;i<n;++i)
		cin >> a >> b,G[a].pb(b),G[b].pb(a),J[i]=J[i-1]*i%MOD;
	dfs(1,1);
	cout << dp[1]*n%MOD << "\n";
}