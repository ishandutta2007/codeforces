#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e5;
const ld E = 1e-9;
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

ull _pow(ull n, ull m){
	ull ans = 1;
	for(ull i = 0; i < m; i++)
		ans *= n;
	return ans;
}

ull solve(ull n){
	if(n == 0)
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

	ull n;
	cin >> n;

	ull len = n * 2 - 2;
	ull ans = 0;

	for(ull i = n; i <= n; i++){
		for(ull j = 0; j + i <= len; j++){
			ull left = j;
			ull right = len - (j + i);
			ull res = solve(left) * solve(right);
			ans += res * 4;
		}
	}

	cout << ans;

}