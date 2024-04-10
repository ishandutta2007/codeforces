#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f(vector<int> a, int h) {

	sort(a.rbegin(), a.rend());
	const int n = (int) a.size();
	for (int i = 1; i < n; i += 2)
		a[i] = 0;
	return accumulate(a.begin(), a.end(), 0LL) <= h;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for (int&x : a)
		cin >> x;

	int lo = 0, hi = n;
	while (lo < hi) {
		const int mid = (lo + hi + 1) / 2;
		if (f(vector<int>(a.begin(), a.begin() + mid), h))
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << lo;
	return 0;
}