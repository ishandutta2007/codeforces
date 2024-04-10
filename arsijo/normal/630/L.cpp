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

ll _pow(ll n, ll m){
	ll ans = 1;
	for(ll i = 0; i < m; i++)
		ans *= n;
	return ans;
}

ll get(ll n, int q){
	n /= _pow(10, q - 1);
	return n % 10;
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

	ll m;
	cin >> m;

	int ar[5] = {1, 3, 5, 4, 2};

	ll n = 0;

	for(int i = 0; i < 5; i++){
		n = n * 10 + get(m, 6 - ar[i]);
	}

	ll ans = 1;
	for(ll i = 1; i <= 5; i++)
		ans = (ans * n) mod;
	if(ans < 10000)
		cout << 0;
	if(ans < 1000)
		cout << 0;
	if(ans < 100)
		cout << 0;
	if(ans < 10)
		cout << 0;
	cout << ans;

}