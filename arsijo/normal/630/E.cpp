#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
template<typename T> T sqr(T t) {
	return t * t;
}
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define input _read("input.txt")
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif
ull _pow(ull n, ull m) {
	ull ans = 1;
	for (ull i = 0; i < m; i++)
		ans *= n;
	return ans;
}

ull solve(ull n) {
	if (n == 0)
		return 1;
	return 3ULL * _pow(4ULL, n - 1);
}

int main() {

	sync;
	cout.precision(10);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll T = 2000000000;
	x1 += T, y1 += T, x2 += T, y2 += T;

	ll a = (x2 - x1) / 2 + 1;
	ll b = (x2 - x1) / 2;

	if(y1 % 2 == 0)
		swap(a, b);

	ull ans = 0;

	if(y1 % 2 == y2 % 2){
		ans += (y1 % 2 ? a : b);
		y1++;
	}

	if(y1 <= y2){
		ll w = (y2 - y1 + 1) / 2;
		ans += w * 1ULL * (a + b);
	}

	cout << ans;

}