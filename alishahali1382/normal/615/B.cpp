#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

ll n, m, ans, u, v;
int dp[MAXN];
int deg[MAXN];
vector<int> G[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v;
		if (u>v) swap(u, v);
		G[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	for (int i=1; i<=n; i++){
		dp[i]=1;
		for (int x : G[i]) dp[i]=max(dp[i], dp[x]+1);
		ans=max(ans,(ll) deg[i]*dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}