#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll x, k;

ll power (ll a, ll b) {
	if (b == 0)
		return 1;
	ll tmp = power (a, b / 2);
	tmp *= tmp;
	tmp %= mod;
	if (b % 2 == 1)
		tmp *= a;
	tmp %= mod;
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> x >> k;
	if (x == 0)
		return cout << 0 << endl, 0;
	x %= mod;
	ll ret = power (2, k + 1) * x % mod;
	ll cur = power (2, k) - 1 + mod % mod;
	cout << (ret - cur + mod) % mod << endl;
}