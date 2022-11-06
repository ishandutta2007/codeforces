#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<bool, int> f(string s) {
	int sum = 0, mn = 0;
	for (const char c : s) {
		if (c == '(')
			++sum;
		else
			mn = min(mn, --sum);
	}
	return {mn >= min(0, sum), sum};
}

int C() {
	int n;
	cin >> n;

	map<int, int> occ;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		auto p = f(s);
		if (p.first)
			++occ[p.second];
	}

	int res = 0;
	for (const pair<int, int> &p : occ) {
		if (p.first >= 0)
			break;
		res += min(p.second, occ[-p.first]);
	}

	res += occ[0] / 2;
	cout << res;
	return 0;
}

int B() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	for (int mask = 0; mask < (1 << n); ++mask) {
		int x = 0;
		for (int i = 0; i < n; ++i)
			x += a[i] * ((mask & (1 << i)) ? 1 : -1);
		if (x % 360 == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

int A() {
	string s;
	cin >> s;

	for (int i = 0; i < 5; ++i) {
		string t;
		cin >> t;
		if (s[0] == t[0] || s[1] == t[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	return B();
}