#include <iostream>
#include <vector>
#include <set>
#define int long long
using namespace std;


const int N = 100 * 1000 + 5;

long long a[N];
set <pair <int, int> > s1;
set <pair <int, int> > s2;
vector <pair < pair <int, int>, int> > ans;
int32_t main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u] += w;
		a[v] -= w;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			s1.insert({a[i], i});
		}
		if (a[i] < 0) {
			s2.insert({-a[i], i});
		}
	}
	while (s1.size()) {
		pair <int, int> p1 = *s1.begin(), p2 = *s2.begin();
		s1.erase(s1.begin());
		s2.erase(s2.begin());
		int x = p1.second, y = p2.second;
		int z = min(a[x], -a[y]);
		a[x] -= z;
		a[y] += z;
		if (a[x] > 0) {
			s1.insert({a[x], x});
		}
		if (a[y] < 0) {
			s2.insert({-a[y], y});
		}
		ans.push_back({{x, y}, z});
	}
	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.first.first << " " << p.first.second << " " << p.second << '\n';
	}
	return 0;
}