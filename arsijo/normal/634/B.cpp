#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
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

const int MM = 100;
bool to[MM][MM];

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ll n, m;
	cin >> m >> n;

	ll dp[42][2];
	ms(dp);

	if((n & 1) != (m & 1)) {
		cout << 0;
		return 0;
	}

	n <<= 1, m <<= 1;
	dp[0][0] = 1;
	for(int i = 1; i < 42; i++) {
		for(int j = 0; j < 2; j++) {
			for(int x = 0; x < 2; x++) {
				for(int y = 0; y < 2; y++) {
					ll sum = (x + y + j);
					ll xxxor = (x ^ y);
					if((sum & 1) == (bool)((m & (1LL << i))) && xxxor == (bool)(n & (1LL << i))){
						dp[i][sum / 2] += dp[i - 1][j];
					}
				}
			}
		}
	}

	cout << dp[41][0] + (n == m ? -2 : 0) << endl;

}