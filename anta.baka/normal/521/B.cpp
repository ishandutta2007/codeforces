#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int mod = (int)1e9 + 9;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	int n; cin >> n;
	map<pii, int> who;
	vector<pii> co(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; who[{x, y}] = i; co[i] = {x, y};
	}
	vi deg(n, 0); // out
	for (int i = 0; i < n; i++) {
		for (int d = -1; d < 2; d++) {
			if (who.count({ co[i].first + d, co[i].second - 1 })) {
				deg[i]++;
			}
		}
	}
	set<int> Q;
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int d = -1; d < 2; d++) {
			int x = co[i].first + d, y = co[i].second + 1;
			ok &= (!who.count({ x, y }) || deg[who[{x, y}]] != 1);
		}
		if (ok) {
			Q.insert(i);
		}
	}
	vi res;
	for (int i = 0; i < n; i++) {
		int j;
		if (!(i & 1)) { // maxi
			j = *--Q.end();
			Q.erase(--Q.end());
		}
		else {
			j = *Q.begin();
			Q.erase(Q.begin());
		}
		res.pb(j);
		pii t = co[j];
		who.erase(t);
		for (int d = -1; d < 2; d++) {
			pii q = { t.first + d, t.second + 1 };
			if (who.count(q)) {
				int u = who[q];
				if (--deg[u] == 1) {
					for (int e = -1; e < 2; e++) {
						pii r = { q.first + e, q.second - 1 };
						if (who.count(r)) {
							Q.erase(who[r]);
						}
					}
				}
			}
		}
		for (int d = -1; d < 2; d++) {
			pii q = { t.first + d, t.second - 1 };
			if (who.count(q)) {
				int u = who[q];
				bool ok = true;
				for (int e = -1; e < 2 && ok; e++) {
					pii r = { q.first + e, q.second + 1 };
					if (who.count(r) && deg[who[r]] == 1) {
						ok = false;
					}
				}
				if (ok) {
					Q.insert(u);
				}
			}
		}
	}
	int ans = 0, pw = 1;
	for (int i = sz(res) - 1; i >= 0; i--) {
		ans = (ans + 1LL * pw * res[i]) % mod;
		pw = 1LL * n * pw % mod;
	}
	cout << ans;
}