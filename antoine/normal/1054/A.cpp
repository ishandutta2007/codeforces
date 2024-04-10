#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;

	ll dur1 = abs(x - y) * t1;
	ll dur2 = (abs(z - x) + abs(x - y)) * t2 + 3*t3;
	cerr << dur1 << ' ' << dur2 << endl;
	cout << (dur2 <= dur1 ? "YES" : "NO");
	return 0;
}