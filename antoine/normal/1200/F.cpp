#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
const int L = 2520;
vector<int> adj[MxN + 9];
int vis[MxN + 9][L];
int dp[MxN + 9][L];
int a[MxN + 9];

/*
 ll lcm(ll x, ll y) {
 return x / __gcd(x, y) * y;
 }
 */

void adv(int &i, int &j) {
	assert(!adj[i].empty());
	assert(0 <= j && j < L);
	j += a[i];
	if (j >= L)
		j -= L;
	i = adj[i][j % (int) adj[i].size()];
}
void dfs(const int I, const int J) {
	assert(!vis[I][J]);

	int i = I, j = J;
	while (!vis[i][j]) {
		vis[i][j] = 1;
		adv(i, j);
	}

	if (vis[i][j] == 1) {
		const int I = i, J = j;
		set<int> s;
		while (vis[i][j] == 1) {
			vis[i][j] = 3;
			adv(i, j);
			s.insert(i);
		}
		assert(i == I && j == J);
		while (!dp[i][j]) {
			dp[i][j] = (int) s.size();
			adv(i, j);
		}
		assert(i == I && j == J);
	}

	const int cnt = dp[i][j];
	i = I, j = J;
	while (vis[i][j] == 1) {
		vis[i][j] = 2;
		dp[i][j] = cnt;
		adv(i, j);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	/*	ll l = 1;
	 for (int i = 2; i <= 10; ++i)
	 l = lcm(l, i);
	 cout << l;*/

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = (a[i] % L + L) % L;
	}

	for (int i = 1; i <= n; ++i) {
		int m;
		cin >> m;
		while (m--) {
			int x;
			cin >> x;
			adj[i].push_back(x);
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < L; ++j)
			if (!vis[i][j])
				dfs(i, j);

	int q;
	cin >> q;
	DBG(q)
	while (q--) {

		int x, y;
		cin >> x >> y;
		y = (y % L + L) % L;
		assert(vis[x][y] >= 1);
		cout << dp[x][y] << '\n';
	}
	return 0;
}