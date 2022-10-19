#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector< pair<int, int> > serv;

bool check(int x1, int x2) {
	int pos = 0;
	bool found = false;
	for (int i = n - 1; i >= 0; --i) {
		if (serv[i].first * (n - i) >= x2) {
			found = true;
			pos = i;
			break;
		}
	}
	if (!found) {
		return false;
	}
	found = false;
	for (int i = pos - 1; i >= 0; --i) {
		if (serv[i].first * (pos - i) >= x1) {
			found = true;
			break;
		}
	}
	return found;
}

pair< vector<int>, vector<int> > print(int x1, int x2) {
	vector<int> a1, a2;
	int pos = 0;
	for (int i = n - 1; i >= 0; --i) {
		a2.push_back(serv[i].second);
		if (serv[i].first * (n - i) >= x2) {
			pos = i;
			break;
		}
	}
	for (int i = pos - 1; i >= 0; --i) {
		a1.push_back(serv[i].second);
		if (serv[i].first * (pos - i) >= x1) {
			break;
		}
	}
	return {a1, a2};
}

void solve() {
	int x1 = 0, x2 = 0;
	cin >> n >> x1 >> x2;
	serv.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> serv[i].first;
		serv[i].second = i;
	}
	sort(serv.begin(), serv.end());
	if (check(x1, x2)) {
		cout << "Yes" << endl;
		auto ans = print(x1, x2);
		cout << ans.first.size() << " " << ans.second.size() << endl;
		for (int x : ans.first) cout << x + 1 << " ";
		cout << endl;
		for (int x : ans.second) cout << x + 1 << " ";
		cout << endl;
	} else if (check(x2, x1)) {
		cout << "Yes" << endl;
		auto ans = print(x2, x1);
		cout << ans.second.size() << " " << ans.first.size() << endl;
		for (int x : ans.second) cout << x + 1 << " ";
		cout << endl;
		for (int x : ans.first) cout << x + 1 << " ";
		cout << endl;
	} else {
		cout << "No" << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}