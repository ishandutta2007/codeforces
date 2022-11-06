#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int res = a.back() - a[0];

	adjacent_difference(a.begin(), a.end(), a.begin());
	a.erase(a.begin());
	sort(a.rbegin(), a.rend());
	res -= accumulate(a.begin(), a.begin() + k - 1, 0);
	cout << res;
	return 0;
}