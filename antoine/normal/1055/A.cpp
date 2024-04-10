#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool f() {

	int n, s;
	cin >> n >> s;
	--s;

	vector<int> a(n), b(n);
	for (int &x : a)
		cin >> x;
	for (int &x : b)
		cin >> x;
	if (!a[0])
		return false;
	if (a[s])
		return true;
	if (!b[s])
		return false;

	for (int i = s + 1; i < n; ++i) {
		if (a[i] && b[i])
			return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << (f() ? "YES" : "NO");
	return 0;
}