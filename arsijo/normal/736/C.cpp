#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
}

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 101;
const int MAX_K = 24;
const int K = MAX_K - 1;
vector<int> v[MAX];
ll dp[2][MAX][MAX_K];

inline void upd(ll &a, ll b) {
	a += b;
	a %= MOD;
}

ll dp2[2][MAX][MAX_K];
int n, k;
void dfs(int pos, int prev = -1) {
	for (int i = 0; i < (int) v[pos].size(); i++) {
		if (v[pos][i] == prev) {
			v[pos].erase(v[pos].begin() + i);
			break;
		}
	}
	for (int a : v[pos]) {
		dfs(a, pos);
	}
	//cout << "MS" << endl;
	ms(dp2);
	if (!v[pos].empty()) {
		//cout << "! " << pos << endl;
		int a = v[pos][0];
		for (int i = 0; i < K; i++) {
			//cout << dp[0][a][i] << " $ " << dp[1][a][i] << endl;
			if(i)
				upd(dp2[0][0][i - 1], dp[0][a][i]);
			else
				upd(dp2[1][0][0], dp[0][a][i]);
			upd(dp2[1][0][i + 1], dp[1][a][i]);
		}
		for (int z = 1; z < (int) v[pos].size(); z++) {
			int a = v[pos][z];
			for (int i = 0; i <= k + 1; i++) {
				for (int j = 0; j <= k + 1; j++) {
					upd(dp2[0][z][max(i - 1, j)],
							dp2[0][z - 1][j] * dp[0][a][i]);
					if (i - 1 >= j)
						upd(dp2[0][z][i - 1],
								dp2[1][z - 1][j] * dp[0][a][i]);
					else
						upd(dp2[1][z][j], dp2[1][z - 1][j] * dp[0][a][i]);
				}
			}
			for (int i = 0; i <= k + 1; i++) {
				for (int j = 0; j <= k + 1; j++) {
					upd(dp2[1][z][max(i + 1, j)],
							dp2[1][z - 1][j] * dp[1][a][i]);
					if (i + 1 <= j)
						upd(dp2[0][z][j],
								dp2[0][z - 1][j] * dp[1][a][i]);
					else
						upd(dp2[1][z][i + 1], dp2[0][z - 1][j] * dp[1][a][i]);
				}
			}
		}
		int z = (int) v[pos].size() - 1;
		//cout << pos << " " << z << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < MAX_K; j++) {
				if(dp2[i][z][j]){
					//cout << i << " " << z << " " << j << " " << dp2[i][z][j] << endl;
				}
				upd(dp[i][pos][j], dp2[i][z][j]);
				if (i) {
					if (j <= k) {
						upd(dp[0][pos][k], dp2[i][z][j]);
					}
				} else {
					upd(dp[0][pos][k], dp2[i][z][j]);
				}
			}
		}
	} else {
		dp[1][pos][0] = 1;
		dp[0][pos][k] = 1;
	}
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> k;

	for(int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	ll ans = 0;
	for(int i = 0; i <= k; i++) {
		upd(ans, dp[0][1][i]);
	}

	cout << ans << endl;

}