#include <bits/stdc++.h>
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
	int curr = a[0];
	ll ans = 0;
	for (const int &x : a) {
		if (curr > x) {
			ans += curr - x;
			curr = x;
		}
		++ans;
		--curr;
	}
	ans += max(0, curr);
	cout << accumulate(a.begin(), a.end(), 0LL) - ans;
	return 0;
}