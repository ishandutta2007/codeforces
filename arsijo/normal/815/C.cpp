#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define prev __prev
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
	putchar(' ');
}

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 5e3 + 10;

ll dp[MAX][MAX][2];

const ll INF = 1e18;

inline void upd(ll &a, ll b) {
	a = min(a, b);
}

int n, b;

vector<int> vec[MAX];

int c[MAX], d[MAX];

multiset<int> s[MAX];

int sz[MAX];

bool cmp(int a, int b) {
	return sz[a] > sz[b];
}

void dfs(int pos) {
	sz[pos] = 1;
	dp[pos][1][1] = c[pos] - d[pos];
	dp[pos][1][0] = c[pos];
	vector<int> v;
	for (int a : vec[pos]) {
		dfs(a);
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (int a : v) {
		for (int i = sz[pos]; i >= 0; i--) {
			for (int j = 1; j <= sz[a]; j++) {
				if(i)
				upd(dp[pos][i + j][1],
						dp[pos][i][1] + min(dp[a][j][0], dp[a][j][1]));
				upd(dp[pos][i + j][0], dp[pos][i][0] + dp[a][j][0]);
			}
		}
		sz[pos] += sz[a];
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

	cin >> n >> b;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = INF;
		}
	}

	for(int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
		if(i > 1) {
			int a;
			cin >> a;
			vec[a].push_back(i);
		}
	}

	dfs(1);

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		if(dp[1][i][0] <= b) {
			//cout << "0 " << i << endl;
			ans = max(ans, i);
		}
		if(dp[1][i][1] <= b) {
			//cout << "1 " << i << endl;
			ans = max(ans, i);
		}
	}

	cout << ans << endl;

}