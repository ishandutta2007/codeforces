#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.rbegin(), a.rend());
	return min(n - 2, a[1] - 1);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	const int i = max_element(a.begin(), a.end()) - a.begin();
	bool ok = true;
	ok &= is_sorted(a.begin(), a.begin() + i + 1);
	ok &= is_sorted(a.rbegin(), a.rbegin() + n - i);
	ok &= set<int>(a.begin(), a.end()).size() == n;
	cout << (ok ? "YES" : "NO");
	return 0;
}