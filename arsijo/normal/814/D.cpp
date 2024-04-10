#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
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
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
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
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
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

int n;
const int MAX = 1e3 + 10;

struct c{
	ld x, y, r;
};

bool operator<(c a, c b){
	return a.r < b.r;
}

ld dist(c a, c b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

bool check_in(c a, c b){
	return dist(a, b) < max(a.r, b.r);
}

vector<c> v;

vector<int> vec[MAX];
int prev[MAX];

ld dp[MAX][3];

void dfs(int pos){
	for(int a : vec[pos])
		dfs(a);
	dp[pos][0] = 0;
	for(int a : vec[pos]){
		dp[pos][0] += max(dp[a][1], dp[a][2]) + sqr(v[a].r);
	}
	dp[pos][1] = 0;
	for(int a : vec[pos]){
		dp[pos][1] += max(dp[a][0] - sqr(v[a].r), dp[a][2] + sqr(v[a].r));
	}
	dp[pos][2] = 0;
	for(int a : vec[pos]){
		dp[pos][2] += dp[a][1] - sqr(v[a].r);
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

	cin >> n;

	for(int i = 0; i < n; i++){
		c a;
		cin >> a.x >> a.y >> a.r;
		v.push_back(a);
	}
	c a;
	a.x = a.y = 0;
	a.r = 1e9;
	v.push_back(a);

	sort(v.rbegin(), v.rend());

	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 0; j--){
			if(check_in(v[i], v[j])){
				vec[j].push_back(i);
				prev[i] = j;
				break;
			}
		}
	}

	dfs(0);

	ld ans = 0;
	for(int a : vec[0]){
		ans += max(dp[a][1], dp[a][2]) + sqr(v[a].r);
	}

	cout << ans * M_PI << endl;

}