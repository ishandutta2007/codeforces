#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
const int Y = 100100;
long long arr[Y];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long x, n, m;
		bool res = false;
		cin >> x >> n >> m;
		while (x > 20 && n > 0) {
			--n;
			x = (x / 2) + 10;
		}
		res = ((10 * m) >= x);
		if (res)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}