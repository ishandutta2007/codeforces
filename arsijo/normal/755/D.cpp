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

const int MAX = 1e6 + 1;

int t[MAX];

int sum(int pos) {
	int ans = 0;
	for (int i = pos; i >= 0; i &= (i + 1), i--) {
		ans += t[i];
	}
	return ans;
}

int sum(int l, int r) {
	if (l > r)
		return 0;
	return sum(r) - sum(l - 1);
}

void upd(int pos, int val) {
	for (int i = pos; i < MAX; i |= (i + 1)) {
		t[i] += val;
	}
}

int n;

int solve(int l, int r) {
	if (l <= r) {
		return sum(l, r);
	} else {
		return sum(l, n) + sum(1, r);
	}
}

bool in(int l, int r, int pos) {
	if (r < l) {
		r += n;
	}
	return (l <= pos && pos <= r);
}

int dist(int l, int r){
	if(r < l){
		r += n;
	}
	return r - l;
}

void add(int &a, int k){
	a += k;
	if(a > n){
		a -= n;
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

	int k;
	cin >> n >> k;

	int pos = 1;
	int next = pos + k;
	vector<ii> v;
	int l = 2, r = 1;
	for(int i = 2; i < next; i++){
		if(i + k <= n){
			r = i;
		}else{
			break;
		}
	}
	assert(r != 1);
	v.push_back(make_pair(l, r));
	r = n, l = n + 1;
	for(int i = n; i > next; i--){
		if(i + k - n > 1){
			l = i;
		}else{
			break;
		}
	}
	assert(l != n + 1);
	v.push_back(make_pair(l, r));
	ll ans = 1;
	for(int i = 1; i <= n; i++) {
		int next = pos;
		add(next, k);
		for(ii a : v){
			//cout << "? " << a.first << " " << a.second << " " << solve(a.first, a.second) << endl;
			ans += solve(a.first, a.second);
		}
		ans++;
		upd(pos, 1);
		//cout << "+ " << pos << endl;
		write(ans);
		putchar(' ');
		pos = next;
		for(ii &a : v){
			add(a.first, k);
			add(a.second, k);
		}
	}

}