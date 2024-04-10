#include <bits/stdc++.h>
using namespace std;

vector<int> go(int n, int k) {
	vector<int> v, vl, vr;
	if(k == 1) {
		for(int i = 1; i <= n; i++) v.push_back(i);
		return v;
	}
	k--;
	int xl = n / 2, xr = (n + 1) / 2;
	if(2 * xl - 1 >= k) {
		vl = go(xl, k - 1);
		vr = go(xr, 1);
	} else {
		vl = go(xl, 2 * xl - 1);
		vr = go(xr, k - (2 * xl - 1));
	}
	for(int el : vl) v.push_back(el + xr);
	for(int el : vr) v.push_back(el);
	return v;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	if(k % 2 == 0 || k > 2 * n - 1) return cout << -1, 0;
	vector<int> v = go(n, k);
	for(int x : v) cout << x << ' ';
}