#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a)
		cin >> x;
	for (int &x : b)
		cin >> x;

	int ans = 0;
	map<long double, int> mp;

	for (int i = 0; i < n; ++i) {
		if (!a[i])
			ans += !b[i];
		else
			++mp[(long double)(b[i]) / a[i]];
	}

	cout << ans + accumulate(mp.begin(), mp.end(), 0, [](const int &acc, const pair<long double, int> &p) {
		return max(acc, p.second);
	});

	return 0;
}