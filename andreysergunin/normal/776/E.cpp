#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int P = 1e9 + 7;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

ll phi(ll n) {
	ll ans = 1;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			for (; n % i == 0; n /= i) 
				ans *= i;
			ans /= i;
			ans *= (i - 1);
		}
	}
	if (n > 1)
		ans *= n - 1;
	return ans;
}

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < k + 1 && n > 1; ++i) {
		if (i & 1)
			n = phi(n);
	}

	n %= P;
	cout << n << endl;

}