#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
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

const int MAX = 1E5 + 10;
const int MAX_LOG = 18;
vector<int> vec[MAX];
int t[MAX_LOG][MAX];
int d[MAX];
int timer;
int tin[MAX], tout[MAX];

void dfs(int pos, int prev = 0){
	t[0][pos] = prev;
	tin[pos] = ++timer;
	for(int i = 1; i < MAX_LOG; i++){
		t[i][pos] = t[i - 1][t[i - 1][pos]];
	}
	for(int a : vec[pos]){
		if(a != prev){
			d[a] = d[pos] + 1;
			dfs(a, pos);
		}
	}
	tout[pos] = ++timer;
}

inline bool upper(int a, int b){
	return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

int lca(int a, int b){
	if(upper(a, b))
		return a;
	if(upper(b, a))
		return b;
	for(int i = MAX_LOG - 1; i >= 0; i--){
		if(t[i][a] && !upper(t[i][a], b)){
			a = t[i][a];
		}
	}
	return t[0][a];
}

int dist(int a, int b){
	return (d[a] + d[b] - 2 * d[lca(a, b)]);
}

int solve(int a, int b, int c){
	int q = dist(a, b);
	int w = dist(b, c);
	int e = dist(a, c);
	if(q > w){
		swap(q, w);
	}
	if(q > e){
		swap(q, e);
	}
	if(w > e){
		swap(w, e);
	}
	if(e == q + w){
		return w;
	}
	a = q + w - e;
	a /= 2;
	b = q - a;
	c = w - a;
	return max(max(a, b), c);
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

	int n, q;
	cin >> n >> q;

	for(int i = 2; i <= n; i++){
		int a;
		cin >> a;
		vec[a].push_back(i);
		vec[i].push_back(a);
	}
	timer = 0;
	dfs(1);

	while(q--){
		int a, b, c;
		cin >> a >> b >> c;
		cout << solve(a, b, c) + 1 << endl;
	}

}