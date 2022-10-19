#include<bits/stdc++.h>

using namespace std;

int x, y, z;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> x >> y >> z;
	long long res = 2 * z;
	if (x == y) res += 2 * x;
	else res += 2 * min(x, y) + 1;
	cout << res;
	return 0;
}