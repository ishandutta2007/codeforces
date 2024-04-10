#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a[3];
	for (int &x : a)
		cin >> x;

	sort(a, a + 3);
	int ans = max(0, a[2] - (a[0] + a[1]) + 1);
	cout << ans;

	return 0;
}