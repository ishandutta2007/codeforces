#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> co, ro;
vector<pair<int, int>> res;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << ' ' << 1 << ' ' << i << ' ' << n << endl;
		fflush(stdout);
		int u;
		cin >> u;
		if (u % 2) ro.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cout << "? " << 1 << ' ' << i << ' ' << n << ' ' << i << endl;
		fflush(stdout);
		int u;
		cin >> u;
		if (u % 2) co.push_back(i);
	}
	if (ro.size() == 2 && co.size() == 2) {
		cout << "? " << ro[0] << ' ' << co[0] << ' ' << ro[0] << ' ' << co[0] << endl;
		fflush(stdout);
		int u;
		cin >> u;
		if (u % 2) res.push_back(make_pair(ro[0], co[0]));
		cout << "? " << ro[0] << ' ' << co[1] << ' ' << ro[0] << ' ' << co[1] << endl;
		fflush(stdout);
		cin >> u;
		if (u % 2) res.push_back(make_pair(ro[0], co[1]));
		cout << "? " << ro[1] << ' ' << co[1] << ' ' << ro[1] << ' ' << co[1] << endl;
		fflush(stdout);
		cin >> u;
		if (u % 2) res.push_back(make_pair(ro[1], co[1]));
		cout << "? " << ro[1] << ' ' << co[0] << ' ' << ro[1] << ' ' << co[0] << endl;
		fflush(stdout);
		cin >> u;
		if (u % 2) res.push_back(make_pair(ro[1], co[0]));
	} else if (ro.size() == 2 && co.size() == 0) {
		int t = ro[0];
		int l = 1, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			cout << "? " << t << ' ' << l << ' ' << t << ' ' << mid << endl;
			fflush(stdout);
			int u;
			cin >> u;
			if (u % 2) r = mid;
			else l = mid + 1;
		}
		for (int i = r; i >= l; i--) {
			cout << "? " << t << ' ' << i << ' ' << t << ' ' << i << endl;
			fflush(stdout);
			int u;
			cin >> u;
			if (u % 2) {
				res.push_back(make_pair(t, i));
				res.push_back(make_pair(ro[1], i));
			}
		}
	} else if (ro.size() == 0 && co.size() == 2) {
		int t = co[0];
		int l = 1, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			cout << "? " << l << ' ' << t << ' ' << mid << ' ' << t << endl;
			fflush(stdout);
			int u;
			cin >> u;
			if (u % 2) r = mid;
			else l = mid + 1;
		}
		for (int i = r; i >= l; i--) {
			cout << "? " << i << ' ' << t << ' ' << i << ' ' << t << endl;
			fflush(stdout);
			int u;
			cin >> u;
			if (u % 2) {
				res.push_back(make_pair(i, t));
				res.push_back(make_pair(i, co[1]));
			}
		}
	}
	cout << "! " << res[0].first << ' ' << res[0].second << ' ' << res[1].first << ' ' << res[1].second << endl;
	fflush(stdout);
	return 0;
}