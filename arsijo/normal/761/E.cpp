#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-7;
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
#define M_PI acos(-1)
#define remove tipa_remove
#define left tipa_left
#define right tipa_right
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int q = 40;

const int MAX = 31;
vector<int> vec[MAX];
int ar[MAX][MAX];
ll x[MAX], y[MAX];
int X[4] = { 1, 0, -1, 0 };
int Y[4] = { 0, 1, 0, -1 };

void dfs(int pos, int prev = -1, int from = -1) {
	for (int i = 0; i < (int) vec[pos].size(); i++) {
		if (vec[pos][i] == prev) {
			vec[pos].erase(vec[pos].begin() + i);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (from != i && !vec[pos].empty()) {
			int a = vec[pos].back();
			vec[pos].pop_back();
			x[a] = x[pos] + X[i] * (1LL << q);
			y[a] = y[pos] + Y[i] * (1LL << q);
			q--;
			dfs(a, pos, (i + 2) % 4);
		}
	}
	if(!vec[pos].empty()){
		cout << "NO" << endl;
		exit(0);
	}
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	for(int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
		ar[a][b] = ar[b][a] = true;
	}

	dfs(1);

	cout << "YES" << endl;
	for(int i = 1; i <= n; i++){
		cout << x[i] << " " << y[i] << endl;
	}

}