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

const int MAX_N = 2e5;
const int MAX_SIZE = MAX_N * 19 * 4;

int left[MAX_SIZE], right[MAX_SIZE], sum[MAX_SIZE];

int ar[MAX_N];

int sz;

void build(int v, int l, int r){
	if(l == r)
		return;
	left[v] = ++sz;
	right[v] = ++sz;
	int x = (l + r) >> 1;
	build(left[v], l, x);
	build(right[v], x + 1, r);
}

int upd(int v_old, int l, int r, int pos){
	//cout << "upd " << pos << endl;
	int v = ++sz;
	if(l == r){
		sum[v] = 1;
		return v;
	}
	int x = (l + r) >> 1;
	if(pos <= x){
		left[v] = upd(left[v_old], l, x, pos);
		right[v] = right[v_old];
	}else{
		left[v] = left[v_old];
		right[v] = upd(right[v_old], x + 1, r, pos);
	}
	sum[v] = sum[left[v]] + sum[right[v]];
	return v;
}

int get_sum(int v, int tl, int tr, int r){
	if(tr <= r)
		return sum[v];
	if(r < tl)
		return 0;
	int x = (tl + tr) >> 1;
	return get_sum(left[v], tl, x, r) + get_sum(right[v], x + 1, tr, r);
}

vector<int> vec[MAX_N];

int roots[MAX_N];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++){
		cin >> ar[i];
	}

	sz = 0;

	int root = ++sz;

	build(1, 1, n);

	for(int i = n; i; i--){
		vec[ar[i]].push_back(i);
		if((int) vec[ar[i]].size() > k){
			root = upd(root, 1, n, vec[ar[i]][(int) vec[ar[i]].size() - 1 - k]);
		}
		roots[i] = root;
	}
	cin >> k;
	int last = 0;

	while(k--){
		int l, r;
		cin >> l >> r;
		l = (l + last) % n + 1;
		r = (r + last) % n + 1;
		if(l > r)
			swap(l, r);
		last = r - l + 1 - get_sum(roots[l], 1, n, r);
		cout << last << endl;
	}

}