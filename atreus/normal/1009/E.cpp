#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e6 + 5;
const int mod = 998244353;
ll tav[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	tav[0] = 1;
	for (int i = 1; i <= n; i++)
		tav[i] = (tav[i - 1] * 2) % mod;

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i < n) {
			ans += ((a[i] * (n - i) % mod) * tav[n - i - 1]) % mod;
			ans %= mod;
		}
		ans += (a[i] * tav[n - i]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}