#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<set<pair<int, int>>> s(2);
	int n;
	cin >> n;
	vector<int> l(n), r(n), t(n);
	for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> t[i];
        t[i]--;
	}
	vector<pair<int, pair<int, int>>> e;
	for (int i = 0; i < n; i++) {
		e.pb(l[i], make_pair(0, i));
		e.pb(r[i], make_pair(1, i));
	}
	sort(all(e));
	int ans = 0;
	for (auto c : e) {
		int i = c.se.se;
		if (c.se.fi == 1) {
			int j = t[i];
			int k = j ^ 1;
			if (s[j].count({r[i], i}) && !s[k].empty()) {
				ans++;
				s[k].erase(s[k].begin());
			}
			if (s[j].count({r[i], i})) s[t[i]].erase({r[i], i});
		} else {
			s[t[i]].insert({r[i], i});
		}
	}

	printf("%d\n", n - ans);
}