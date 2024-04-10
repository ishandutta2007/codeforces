#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	for (int i = n - 2; i >= 0; --i)
		a[i] = max(0LL, min(a[i], a[i + 1] - 1));
	cout << accumulate(a.begin(), a.end(), 0LL);
	return 0;
}