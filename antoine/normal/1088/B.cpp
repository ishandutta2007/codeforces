#include <bits/stdc++.h>

using namespace std;
typedef int ll;

const ll mod = (int) 2e5;
ll a[(int) 1e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n && k; ++i) {
		ll curr = a[i] - a[i - 1];
		if (curr) {
			cout << a[i] - a[i - 1] << '\n';
			k--;
		}
	}
	while(k--)
		cout << "0\n";

	return 0;
}