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

void no() {
	cout << "NO" << endl;
	exit(0);
}

struct segment_tree {
	int *t, *y, n;
	segment_tree() {
		n = 1e4 + 1;
		t = new int[n << 2];
		y = new int[n << 2];
		for (int i = 0; i < n; i++) {
			t[i] = y[i] = 0;
		}
	}
	int get(int v, int l, int r, int &can) {
		if (!can) {
			return 0;
		}
		if(t[v] <= can){
			can -= t[v];
			return y[v];
		}
		if(l == r){
			int a = min(can, t[v]);
			can -= a;
			return a * l;
		}
		int x = (l + r) >> 1;
		int ans = get(v << 1 | 1, x + 1, r, can);
		ans += get(v << 1, l, x, can);
		return ans;
	}
	void upd(int v, int l, int r, int pos, int val){
		if(l == r){
			t[v] += val;
			y[v] = t[v] * l;
			return;
		}
		int x = (l + r) >> 1;
		if(pos <= x){
			upd(v << 1, l, x, pos, val);
		}else{
			upd(v << 1 | 1, x + 1, r, pos, val);
		}
		t[v] = t[v << 1] + t[v << 1 | 1];
		y[v] = y[v << 1] + y[v << 1 | 1];
	}
	int get(int can){
		return get(1, 0, n - 1, can);
	}
	void upd(int pos, int val){
		upd(1, 0, n - 1, pos, val);
	}
};

const int MAX = 2e5 + 1;

int a[MAX], b[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	segment_tree tree;
	int n, w, k;
	cin >> n >> w >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	int now = 0;
	int ans = 0;
	int need_time = 0;
	for(int i = 0, l = 0; i < n; i++){
		need_time += b[i];
		now += a[i];
		tree.upd((b[i]) / 2, 1);
		while(need_time - tree.get(w) > k){
			need_time -= b[l];
			now -= a[l];
			tree.upd((b[l] / 2), -1);
			l++;
		}
		ans = max(ans, now);
	}
	cout << ans << endl;

}