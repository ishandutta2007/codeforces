#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << 2 * c + 2 * min(a, b) + (max(a, b) != min(a, b)) << endl;
	return 0;
}