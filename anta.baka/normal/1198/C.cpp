#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;



int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vi kek(3 * n, -1);
		vi mt;
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; --u; --v;
			if (kek[u] == -1 && kek[v] == -1) {
				mt.pb(i);
				kek[u] = kek[v] = 1;
			}
		}
		if (sz(mt) >= n) {
			cout << "Matching\n";
			for (int i = 0; i < n; i++) {
				cout << mt[i] + 1 << ' ';
			}
			cout << '\n';
		}
		else {
			cout << "IndSet\n";
			for (int i = 0, cnt = 0; i < 3 * n && cnt < n; i++) {
				if (kek[i] == -1) {
					cout << i + 1 << ' ';
					cnt++;
				}
			}
			cout << '\n';
		}
	}
}