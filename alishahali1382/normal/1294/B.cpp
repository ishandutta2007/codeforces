#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
typedef pair<int , int> pii;
int main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
	vector<pii> v;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		v.push_back(make_pair(y, x));
	}
	sort(all(v));
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (v[i].second < v[i - 1].second) 
			{ flag = false; }
	}
	if (!flag) {
		cout << "NO" << endl;
		continue;
	}
	string t = "";
	for (int i = 1; i <= n; i++) {
		int dx = v[i].second - v[i - 1].second;
		int dy = v[i].first - v[i - 1].first;
		while (dx--) t += 'R';
		while (dy--) t += 'U';
	}
	cout << "YES" << endl;
	cout << t << endl;
	}
	return 0;
}