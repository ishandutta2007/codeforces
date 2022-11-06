#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a[4];
	for (ll &x : a)
		cin >> x;
	sort(a, a + 4);
	for (int i = 0; i < 3; ++i)
		cout << a[3] - a[i] << ' ';
	return 0;
}