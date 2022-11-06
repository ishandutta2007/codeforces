#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	const ll sum = accumulate(a.begin(), a.end(), 0LL);
	cout << (sum % 2 == 0 && sum - a.back() >= a.back() ? "YES" : "NO");
	return 0;
}