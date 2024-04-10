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
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct fenwick_tree {
	int *t, n;
	fenwick_tree(int n) {
		t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = 0;
		}
		this->n = n;
	}
	void add(int pos, int val) {
		for (int i = pos; i < n; i |= (i + 1)) {
			t[i] += val;
		}
	}
	int sum(int pos) {
		int ans = 0;
		for (int i = pos; i >= 0; i &= (i + 1), i--) {
			ans += t[i];
		}
		return ans;
	}
};

int n;
const int MAX = 2e5 + 10;
const int MAX_SIZE = 1567;
const int M = MAX / MAX_SIZE + 10;
int ar[MAX];
vector<fenwick_tree> v;

int solve_left(int p) {
	int pos = p - 1;
	int ans = 0;
	while (pos >= 0 && pos / MAX_SIZE == p / MAX_SIZE) {
		if (ar[pos] > ar[p]) {
			ans++;
		}
		pos--;
	}
	if (pos >= 0) {
		for (int i = pos / MAX_SIZE; i >= 0; i--) {
			ans += v[i].sum(n - 1) - v[i].sum(ar[p]);
		}
	}
	return ans;
}

int solve_right(int p) {
	int pos = p + 1;
	int ans = 0;
	while (pos < n && pos / MAX_SIZE == p / MAX_SIZE) {
		if (ar[pos] < ar[p]) {
			ans++;
		}
		pos++;
	}
	if (pos < n) {
		for (int i = pos / MAX_SIZE; i <= (n - 1) / MAX_SIZE; i++) {
			ans += v[i].sum(ar[p]);
		}
	}
	return ans;
}

int solve(int p) {
	return solve_left(p) + solve_right(p);
}

void change(int pos, int val) {
	v[pos / MAX_SIZE].add(ar[pos], -1);
	ar[pos] = val;
	v[pos / MAX_SIZE].add(ar[pos], +1);
}

int solve_long(){
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(ar[i] > ar[j]){
				ans++;
			}
		}
	}
	return ans;
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

	int q;
	cin >> n >> q;
	int w = n / MAX_SIZE + 2;
	for(int j = 0; j < w; j++) {
		v.push_back(fenwick_tree(n));
	}

	for(int i = 0; i < n; i++) {
		v[i / MAX_SIZE].add(i, +1);
		ar[i] = i;
	}

	ll ans = 0;

	while(q--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		ans -= solve(a);
		ans -= solve(b);
		if(ar[min(a, b)] > ar[max(a, b)]) {
			ans++;
		}
		int c = ar[a], d = ar[b];
		change(a, d);
		change(b, c);
		ans += solve(a);
		ans += solve(b);
		if(ar[min(a, b)] > ar[max(a, b)]) {
			ans--;
		}
		cout << ans << endl;
	}

}