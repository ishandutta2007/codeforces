#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, ans[MAXN], C;
vector<int> vec; 
string s;
bool vis[MAXN][2];

void dfs(int v, int o) {
	if (vis[v][o]) return;
	vis[v][o] = true;
	if (o == 0) vec.push_back(v);
	C++;

	if (v > 0) {
		if (o == 0 && s[v - 1] == 'L') dfs(v - 1, 1 - o);
		if (o == 1 && s[v - 1] == 'R') dfs(v - 1, 1 - o);
	}

	if (v < n) {
		if (o == 0 && s[v] == 'R') dfs(v + 1, 1 - o);
		if (o == 1 && s[v] == 'L') dfs(v + 1, 1 - o);
	}
}

inline int solve() {
	for (int i = 0; i < 2 * n + 10; i++) vis[i][0] = vis[i][1] = 0, ans[i] = 0;
	cin >> n >> s;

	for (int i = 0; i <= n; i++) {
		if (!vis[i][0]) {
			C = 0;
			vec.clear();
			dfs(i, 0);
			for (int v : vec) ans[v] = max(ans[v], C);
		}

		if (!vis[i][1]) {
			C = 0;
			vec.clear();
			dfs(i, 1);
			for (int v : vec) ans[v] = max(ans[v], C);
		}
	} 
	
	for (int i = 0; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}