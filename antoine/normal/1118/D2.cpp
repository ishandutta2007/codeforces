#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	sort(a.rbegin(), a.rend());

	int lo = 1, hi = n + 1;
	while (lo < hi) {
		const int mid = (lo + hi) / 2;

		ll sum = 0;
		for (int i = 0; i < n; ++i)
			sum += max(0, a[i] - i / mid);
		if (sum >= m)
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << (lo > n ? -1 : lo);
	return 0;
}