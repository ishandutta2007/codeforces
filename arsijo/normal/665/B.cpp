#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
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
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
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

bool check(int a, int b, int c) {
	return a < b && b < c;
}

bool check(int a, int b, int c, int d) {
	return check(a, c, b) || check(a, d, b) || check(c, a, d) || check(c, b, d);
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int a, b, n;
	cin >> a >> b >> n;

	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	int ans = 0;
	for(int q = 0; q < a * b; q++){
		int t;
		cin >> t;
		int pos;
		for(int i = 0; i < n; i++){
			ans++;
			if(ar[i] == t){
				pos = i;
				break;
			}
		}
		for(int i = pos; i >= 1; i--)
			ar[i] = ar[i - 1];
		ar[0] = t;
	}

	cout << ans << endl;

}