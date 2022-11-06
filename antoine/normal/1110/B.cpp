#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int ans = a.back() - a[0] + 1;

	adjacent_difference(a.begin(), a.end(), a.begin());
	a.erase(a.begin());

	sort(a.begin(), a.end());
	while (k > 1 && !a.empty()) {
		ans -= a.back() - 1;
		a.pop_back();
		k--;
	}
	cout << ans;
	return 0;
}