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
	int n; cin >> n;
	vi a(n);
	vi atm(n);
	set<pii> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert({ a[i], i });
		atm[i] = 0;
	}
	vi st;
	vi tm;
	int tik_tak = 0;
	int q; cin >> q;
	while (q--) {
		tik_tak++;
		int tp; cin >> tp;
		if (tp == 1) {
			int p, x; cin >> p >> x; --p;
			a[p] = x; atm[p] = tik_tak;
		}
		else {
			int x; cin >> x;
			while (!st.empty() && x >= st.back()) {
				st.pop_back(); tm.pop_back();
			}
			st.pb(x); tm.pb(tik_tak);
		}
	}
	for (int i = 0; i < n; i++) {
		if (tm.empty() || tm.back() <= atm[i]) {
			cout << a[i] << ' ';
		}
		else {
			int lf = 0, rg = sz(tm) - 1;
			while (lf < rg) {
				int md = (lf + rg) >> 1;
				if (tm[md] > atm[i]) {
					rg = md;
				}
				else {
					lf = md + 1;
				}
			}
			cout << max(a[i], st[lf]) << ' ';
		}
	}
}