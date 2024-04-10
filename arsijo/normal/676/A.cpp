#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 9;
const ld E = 1e-9;
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;
int ar[100];

int solve(int l, int r){
	swap(ar[l], ar[r]);
	int pos1, pos2;
	for(int i = 0; i < n; i++){
		if(ar[i] == 1){
			pos1 = i;
		}else if(ar[i] == n){
			pos2 = i;
		}
	}
	swap(ar[l], ar[r]);
	return abs(pos2 - pos1);
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(40);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ans = max(ans, solve(i, j));
		}
	}

	cout << ans << endl;

}