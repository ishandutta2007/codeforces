#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <tuple>
using namespace std;

const int N = 600001, mod = 998244353;
long long frac[N], fracp[N];

long long modpow(long long a, int b) {
	long long ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

long long C(int n, int m) {
	return frac[n] * fracp[m] % mod * fracp[n - m] % mod; 
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    frac[0] = 1;
    for (int i = 1; i < N; ++i) frac[i] = frac[i - 1] * i % mod;
    for (int i = 0; i < N; ++i) fracp[i] = modpow(frac[i], mod - 2);
    int n, k, x, y;
    cin >> n >> k;
    vector <pair <int, int>> lamps;
    for (int i = 0; i < n; ++i) {
    	cin >> x >> y;
    	lamps.emplace_back(x, 1);
    	lamps.emplace_back(y + 1, -1);
	}
    sort(lamps.begin(), lamps.end());
    int cnt = 0;
    long long ans = 0;
	for (int i = 0; i < lamps.size(); ++i) {
    	tie(x, y) = lamps[i];
    	cnt += y;
    	if (cnt >= k && y == 1) {
    		ans = (ans + C(cnt - 1, k - 1)) % mod;
		}
	}
	cout << ans << endl;
}