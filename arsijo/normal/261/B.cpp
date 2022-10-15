#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-17;
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

const int M = 51;
ld fac[M];
ld dp[M][M][M];

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

	fac[0] = fac[1] = 1;
	for(int i = 2; i < M; i++){
		fac[i] = fac[i - 1] * i;
	}

	int n;
	cin >> n;
	int ar[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> ar[i];
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += ar[i];
	int w;
	cin >> w;
	if(sum <= w){
		cout << n;
		return 0;
	}
	ld ans = 0;
	for(int t = 1; t <= n; t++){
		ms(dp);
		dp[0][0][ar[t]] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int z = 0; z <= w; z++){
					dp[i][j][z] = dp[i - 1][j][z];
				}
			}
			if(i == t)
				continue;
			for(int j = 1; j <= n; j++){
				for(int z = ar[i]; z <= w; z++){
					dp[i][j][z] += dp[i - 1][j - 1][z - ar[i]];
				}
			}
		}
		for(int i = 0; i <= w; i++){
			for(int j = 0; j <= n; j++){
				if(dp[n][j][i]){
					ld r = dp[n][j][i] * fac[j] * fac[n - j - 1];
					//cout << "+ " << r << endl;
					ans += r / fac[n];
				}
			}
		}
	}

	cout << ans << endl;

}