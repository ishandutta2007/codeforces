#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int s[n], t[n];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	vector<vector<int>> ans;
	sort(t, t + n);
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int a, int b) {
		return s[a] < s[b];
	});
	vector<int> st;
	for(int i = 0; i < n; i++) {
		if(s[p[i]] < t[i]) {
			st.push_back(i);
		} else {
			while(s[p[i]] > t[i]) {
				if(st.empty()) {
					cout << "NO" << endl;
					return 0;
				} else {
					int d = min(t[st.back()] - s[p[st.back()]], s[p[i]] - t[i]);
					s[p[st.back()]] += d;
					s[p[i]] -= d;
					ans.push_back({p[st.back()] + 1, p[i] + 1, d});
					if(s[p[st.back()]] == t[st.back()]) {
						st.pop_back();
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(s[p[i]] != t[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(auto it: ans) {
		for(auto jt: it) {
			cout << jt << ' ';
		}
		cout << "\n";
	}
	return 0;
}