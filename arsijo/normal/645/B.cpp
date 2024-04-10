#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int ans = 0;

void solve(int n, int *ar, int left){
	if(left == 0){
		int res = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(ar[j] < ar[i])
					res++;
		ans = max(ans, res);
		return;
	}
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++){
			swap(ar[i], ar[j]);
			solve(n, ar, left - 1);
			swap(ar[i], ar[j]);
		}
}

int solve_long(int n, int k){
	int ar[n];
	ans = 0;
	for(int i = 0; i < n; i++)
		ar[i] = i;
	solve(n, ar, k);
	return ans;
}

ll solve(int n, int k){
	ll ans = 0;
	k = min(k, n / 2);
	while(k--){
		ans += (n - 2) * 2 + 1;
		n -= 2;
	}
	return ans;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, k;
	cin >> n >> k;

	cout << solve(n, k);

}