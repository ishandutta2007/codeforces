#include<bits/stdc++.h>
using namespace std;
struct ans {
	int d, a[40];
};
map<int, ans> mp;
ans solve(int n) {
	ans res;
	if (n == 1) {
		res.d = 0;
		return res;
	}
	if (mp.find(n) != mp.end()) return mp[n];
	int p = 1;
	while ((1 << p+1)-1 < n) ++p;
	res.d = p;
	if ((1 << p) == n) {
		res.a[1] = 0;
		for (int i = 2; i <= p; i++) res.a[i] = 1 << i-2;
		return mp[n] = res;
	}
	ans tmp1 = solve((n-1)/2), tmp2 = solve(n/2);
	res.a[1] = 1;
	for (int i = 2; i <= p; i++) res.a[i] = tmp1.a[i-1] + tmp2.a[i-1];
	return mp[n] = res;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		mp.clear();
		ans res = solve(n);
		cout << res.d << endl;
		for (int i = 1; i <= res.d; i++) cout << res.a[i] << ' ';
		cout << endl;
	}
}