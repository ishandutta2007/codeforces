#include <bits/stdc++.h>

const int N = 200005, P = 1000000007, INF = 0x3f3f3f3f;

int n;
std::pair<int, int> a[N];

int f[N], mn[N], g[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].first >> a[i].second;
	}
	a[0].second = a[0].first = 0;
	std::sort(a + 1, a + 1 + n);
	f[0] = mn[0] = 0;
	for (int i = 1; i <= n; ++i) {
		// std::cerr << "tttt " << a[i].first << " " << a[i].second << "\n";
		int p = std::upper_bound(a + 1, a + i, std::make_pair(a[i].second, INF)) - a - 1;
		f[i] = mn[p] + a[i].second;
		mn[i] = std::min(mn[i - 1], f[i] - a[i].first);
	}
	std::map<int, std::vector<std::pair<int, int>>> M;
	g[0] = 1;
	M[0].push_back({0, 1});
	for (int i = 1; i <= n; ++i) {
		int x = f[i] - a[i].second;
		int p = std::upper_bound(M[x].begin(), M[x].end(), std::make_pair(a[i].second, P)) - M[x].begin() - 1;
		if (p < 0) {
			g[i] = 0;
		} else {
			g[i] = M[x][p].second;
		}
		// std::cerr << "dfcmd " << g[i] << " " << x << " " << p << "\n";
		x = f[i] - a[i].first;
		int s = M[x].empty() ? g[i] : (M[x].back().second + g[i]) % P;
		M[x].push_back({a[i].first, s});
	}
	int pos = 0;
	int suf_mx = 0;
	for (int i = n; i; --i) {
		if (suf_mx >= a[i].first) {
			pos = i;
			break;
		}
		suf_mx = std::max(suf_mx, a[i].second);
	}
	int mn = *std::min_element(f + pos + 1, f + n + 1);
	int ans = 0;
	for (int i = pos + 1; i <= n; ++i) {
		if (f[i] == mn) {
			ans = (ans + g[i]) % P;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}