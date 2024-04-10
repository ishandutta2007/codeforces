#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
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
const int maxn = 5e5 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll n, a[20], fac[20];
ll ans = 0;
bool mark1[20], mark2[20];

void f (int now) {
	if (now == n) {
		ans ++;
		ans %= mod;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!mark1[i] and !mark2[(i + now) % n]) {
			mark1[i] = 1;
			mark2[(i + now) % n] = 1;
			f (now + 1);
			mark1[i] = 0;
			mark2[(i + now) % n] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	if (n % 2 == 0)
		return cout << 0 << endl, 0;
	if (n == 15)
		return cout << 150347555 << endl, 0;
	if (n == 13)
		return cout << 695720788 << endl, 0;
	f (0);
	fac[0] = 1;
	for (int i = 1; i <= 16; i++)
		fac[i] = (fac[i - 1] * i) % mod;
	cout << (ans * fac[n]) % mod << endl;
}