#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}
	vector<int> x, y;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			y.push_back(p[i]);
		} else {
			x.push_back(p[i]);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	map<int, int> conv;
	for (int i = 0; i < (int)x.size(); ++i) {
		conv[x[i]] = i;
	} 
	for (int i = 0; i < (int)y.size(); ++i) {
		conv[y[i]] = i + (int)x.size();
	}
	for (int i = 0; i < n; ++i) {
		cout << conv[p[i]] + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}