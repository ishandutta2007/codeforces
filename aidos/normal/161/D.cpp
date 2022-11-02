#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1 << 29) - 1;
const int maxn = (int)5e4 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n;
vector<int> g[maxn];
vector<int> gr[maxn];
vector<int> ord;
int k;
void dfs(int v, int p) {
	for(const int &to: g[v]) {
		if(to != p) {
			gr[v].pb(to);
			dfs(to, v);
		}
	}
	ord.pb(v);
}
ll dp[maxn][510];
void solve(){
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, -1);
	ll ans = 0;
	for(const int &id: ord) {
		dp[id][0] = 1;
		for(const int &to: gr[id]) {
			for(int i = k-1; i >= 0; i--) {
				ans += dp[id][i] * dp[to][k-i-1];
				dp[id][i + 1] += dp[to][i];
			}
		}
	}

	cout << ans << "\n";
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}