#include <iostream>
#include <map>
using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;
long long n, m;

map <long long, long long> mp;

long long get(long long x) {
	if (x < 0)
		return 0;
//	cout << x << endl;
	if (mp.find(x) != mp.end())
		return mp[x];
	long long y = x / 2, z = x - x / 2;
	mp[x] += get(y) * get(z);
	mp[x] %= mod;
//	cout << "73 " << x << " " << y << " " << z << " " << mp[x] << endl;
	for (int i = 1; i < m; i++) {
		mp[x] += get(y - i) * get(z - m + i);
		mp[x] %= mod;
	}
	return mp[x];
}
int main() {
	cin >> n >> m;
	mp[0] = 1;
	mp[1] = 1;
	long long ans = get(n);
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << get(i) << endl;
//	}
	cout << ans << endl;
	return 0;
}