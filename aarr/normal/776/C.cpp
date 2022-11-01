#include <iostream>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5;
const long long inf = 200ll * 1000 * 1000 * 1000 * 1000 + 7;

map <long long, int> mp;
int main() {
	int n, k;
	cin >> n >> k;
	mp[0] = 1;
	long long ans = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s += x;
		mp[s]++;
		if (k == 1) {
			ans += mp[s - 1];
			continue;
		}
		if (k == -1) {
			ans += mp[s - 1] + mp[s + 1];
			continue;
		}
		long long y = 1;
		while (abs(y) <= inf) {
			ans += mp[s - y];
			y *= k;
		}
	}
	cout << ans << endl;
	return 0;
}