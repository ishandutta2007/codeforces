#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;


vector <int> vec[N];
vector <pair <int, int> > d[N];
int a[N];
bool mark[N];
int cnt[N];
long long fac[N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

long long chs(int x, int y) {
	if (y > x) 
		return 0;
	long long ans = fac[x];
	ans *= po(fac[y], mod - 2);
	ans %= mod;
	ans *= po(fac[x - y], mod - 2);
	ans %= mod;
	return ans;
}
int get(int x, int y) {
	return (x >> y) & 1;
}
void f(int x) {
	int y = x;
	int z = x;
//	cout << y << endl;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			vec[y].push_back(i);
			x /= i;
			z /= i;
		}
		while (x % i == 0) {
			x /= i;
		}
	}
	if (x > 1) {
		vec[y].push_back(x);
		z /= x;
	}
//	cout << "48 " << y << " " << z << endl;
	for (int mask = 0; mask < (1 << vec[y].size()); mask++) {
		int w = z;
		for (int i = 0; i < vec[y].size(); i++) {
			if (get(mask, i)) {
				w *= vec[y][i];
			}
		}
		d[y].push_back({w, __builtin_popcount(mask) % 2});
	//	cout << "73 " << y << " " << z << endl;
	}
}
int main() {
	ios :: sync_with_stdio(false);
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	for (int i = 1; i < N; i++) {
		f(i);
	}
	int q;
	cin >> q;
	long long ans = 0;
	for (int i = 0; i < q; i++) {
		int n, f;
		cin >> n >> f;
		long long ans = 0;
		for (auto p : d[n]) {
		//	cout << "73 " << n << " " << p.first << " " << p.second << " " << chs(p.first - 1, f - 1) << endl; 
			if (p.second == vec[n].size() % 2) {
				ans += chs(p.first - 1, f - 1);
			}
			else {
				ans += mod - chs(p.first - 1, f - 1);
			}
			ans %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}