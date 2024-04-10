#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 305, mod = 1000 * 1000 * 1000 + 7;

map <int, int> mp;
vector <int> vec;
long long fac[N], facp[N];
long long dp[N][N];

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

int chs(int x, int y) {
	if (y < 0 || x - y < 0) {
		return 0;
	}
	long long ans = fac[x] * facp[y];
	ans %= mod;
	ans *= facp[x - y];
	ans %= mod;
	return ans;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 2; j * j <= x; j++) {
			while (x % (j * j) == 0) {
			//	cout << "72 " << x << " " << j << endl;
				x /= j * j;
			}
		}
		mp[x]++;
		vec.push_back(x);
	}
//	cout << 71 << endl;
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	fac[0] = facp[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
		facp[i] = po(fac[i], mod - 2);
	}
	int s = 0;
	dp[0][0] = 1;
	for (int i = 0; i < vec.size(); i++) {
		int c = mp[vec[i]];
		for (int j = 0; j <= s; j++) {
			for (int k = 0; k <= j; k++) {
				for (int q = 0; q < c; q++) {
					long long z = 1ll * dp[i][j] * fac[c];
					z %= mod;
					z = (z * chs(j, k) % mod) * chs(c - 1, c - q - 1);
					z %= mod;
					z *= chs(s - j + 1, c - q - k);
					z %= mod; 
					dp[i + 1][j - k + q] += z;
					dp[i + 1][j - k + q] %= mod;
				//	cout << "75 " << i << " " << j << " " << k << " " << q << endl;
				//	cout << "73 " << i + 1 << " " << j - k + q << " " << z << endl;
				}
			}
		}
		s += c;
	}
	cout << dp[vec.size()][0];
	return 0;
}