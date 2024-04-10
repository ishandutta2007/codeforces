#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int n, a[100005], pos[1000005], last[1000005];
set<int> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cur = 0;
	vi res;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			if (last[a[i]] > cur) return cout << -1, 0;
			last[a[i]] = i;
			if (s.find(a[i]) != s.end()) return cout << -1, 0;
			s.insert(a[i]);
		} else {
			if (s.find(-a[i]) == s.end()) return cout << -1, 0; 
			s.erase(-a[i]);
			if (s.empty()) {
				res.pb(i - cur);
				cur = i;
			}
		}
	}
	if (!s.empty()) return cout << -1, 0;
	cout << res.size() << endl;
	for (auto u : res) {
		cout << u << ' ';
	}
	return 0;
}