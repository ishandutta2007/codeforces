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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e5 + 1;
vector<ll> vec[MAX << 2];
ll ar[MAX];

void build(int v, int l, int r){
	if(l == r){
		vec[v].push_back(ar[l]);
		return;
	}
	int x = (l + r) >> 1;
	build(v << 1, l, x);
	build(v << 1 | 1, x + 1, r);
	vec[v].reserve(r - l + 1);
	vec[v].resize(r - l + 1);
	merge(vec[v << 1].begin(), vec[v << 1].end(), vec[v << 1 | 1].begin(), vec[v << 1 | 1].end(), vec[v].begin());
}

int find(int v, int tl, int tr, int l, int r, ll val){
	if(l <= tl && tr <= r){
		if(vec[v].back() <= val)
			return (int) vec[v].size();
		l = 0, r = (int) vec[v].size() - 1;
		int x;
		while(l < r){
			x = (l + r) >> 1;
			if(vec[v][x] <= val){
				l = x + 1;
			}else{
				r = x;
			}
		}
		return l;
	}
	if(tr < l || r < tl)
		return 0;
	int x = (tl + tr) >> 1;
	return find(v << 1, tl, x, l, r, val) + find(v << 1 | 1, x + 1, tr, l, r, val);
}

int tin[MAX], tout[MAX], timer;
vector<ii> v[MAX];
ll D[MAX];
int a[MAX];

void dfs(int pos, ll d){
	tin[pos] = ++timer;
	ar[timer] = d - a[pos];
	D[pos] = d;
	for(ii a : v[pos]){
		dfs(a.first, d + a.second);
	}
	tout[pos] = timer;
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

	timer = 0;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 2; i <= n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(make_pair(i, b));
	}
	dfs(1, 0);
	build(1, 1, n);
	for(int i = 1; i <= n; i++){
		cout << find(1, 1, n, tin[i], tout[i], D[i]) - 1 << " ";
	}

}