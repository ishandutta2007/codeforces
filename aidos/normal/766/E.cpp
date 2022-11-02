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
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n;
vector<int> g[maxn];
vector<int> gr[maxn];
int a[maxn];
vector<int> ord;
void dfs(int v, int p) {
	for(const int &to: g[v]) {
		if(to != p) {
			gr[v].pb(to);
			dfs(to, v);
		}
	}
	ord.pb(v);
}
ll dp[maxn][2];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, -1);
	ll ans = 0;
	for(int i = 0; i < 20; i++) {
		ll cur = 0;
		for(const int &id: ord) {
			int x = (a[id]>>i) & 1;
			dp[id][x] = 1;
			dp[id][1-x] = 0;
			cur += x;
			for(const int &to: gr[id]) {
				cur += dp[id][0] * dp[to][1];
				cur += dp[id][1] * dp[to][0];
				dp[id][x] += dp[to][0];
				dp[id][1-x] += dp[to][1];
			}
		}
		ans += cur << i;
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