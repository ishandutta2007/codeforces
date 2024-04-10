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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct fenwick_tree {
private:
	int *t, n;
public:
	fenwick_tree(int n) {
		t = new int[n];
		this->n = n;
		for (int i = 0; i < n; i++) {
			t[i] = 0;
		}
	}
	void upd(int pos, int val) {
		for (int i = pos; i >= 0; i &= (i + 1), i--) {
			t[i] = max(t[i], val);
		}
	}
	int get(int pos) {
		int ans = 0;
		for (int i = pos; i < n; i |= (i + 1)) {
			ans = max(ans, t[i]);
		}
		return ans;
	}
};

struct segment_tree {
private:
	int *t, n;
	fenwick_tree **trees;
	vector<int> *vec;
	int get(int v, int l, int r, int pos) {
		if (t[v] || l == r)
			return t[v];
		int x = (l + r) >> 1;
		return (pos <= x ?
				get(v << 1, l, x, pos) : get(v << 1 | 1, x + 1, r, pos));
	}
	void push(int v) {
		if (t[v]) {
			t[v << 1] = t[v << 1 | 1] = t[v];
			t[v] = 0;
		}
	}
	void upd(int v, int tl, int tr, int l, int r, int val, int val2) {
		if (l <= tl && tr <= r) {
			t[v] = val;
			int l = 0, r = (int) vec[v].size();
			while (l < r) {
				int x = (l + r) >> 1;
				if (vec[v][x] < val2) {
					l = x + 1;
				} else {
					r = x;
				}
			}
			assert(vec[v][l] == val2);
			trees[v]->upd(l, val);
			return;
		}
		if (tr < l || r < tl)
			return;
		push(v);
		int x = (tl + tr) >> 1;
		upd(v << 1, tl, x, l, r, val, val2);
		upd(v << 1 | 1, x + 1, tr, l, r, val, val2);
	}

	void pre_add(int v, int tl, int tr, int l, int r, int val) {
		if (l <= tl && tr <= r) {
			vec[v].push_back(val);
			return;
		}
		if (tr < l || r < tl)
			return;
		int x = (tl + tr) >> 1;
		pre_add(v << 1, tl, x, l, r, val);
		pre_add(v << 1 | 1, x + 1, tr, l, r, val);
	}
	void make(int v, int l, int r) {
		if (!vec[v].empty()) {
			trees[v] = new fenwick_tree((int) vec[v].size());
			sort(vec[v].begin(), vec[v].end());
		}
		if (l == r)
			return;
		int x = (l + r) >> 1;
		make(v << 1, l, x);
		make(v << 1 | 1, x + 1, r);
	}
	int get2(int v, int tl, int tr, int pos, int g){
		int ans = 0;
		if(!vec[v].empty() && vec[v].back() >= g){
			int l = 0, r = (int) vec[v].size() - 1;
			while(l < r){
				int x = (l + r) >> 1;
				if(vec[v][x] < g){
					l = x + 1;
				}else{
					r = x;
				}
			}
			ans = trees[v]->get(l);
		}
		if(tl != tr){
			int x = (tl + tr) >> 1;
			ans = max(ans, pos <= x ? get2(v << 1, tl, x, pos, g) : get2(v << 1 | 1, x + 1, tr, pos, g));
		}
		return ans;
	}
public:
	segment_tree(int n) {
		trees = new fenwick_tree*[n << 2];
		this->n = n - 1;
		vec = new vector<int> [n << 2];
		t = new int[n << 2];
		for (int i = 0; i < (n << 2); i++) {
			t[i] = 0;
		}
	}
	void make() {
		make(1, 1, n);
	}
	void pre_add(int l, int r, int val) {
		pre_add(1, 1, n, l, r, val);
	}
	int get(int pos) {
		return get(1, 1, n, pos);
	}
	int get2(int pos, int h){
		return get2(1, 1, n, pos, h);
	}
	void upd(int l, int r, int val, int val2) {
		upd(1, 1, n, l, r, val, val2);
	}
} tree((int) 1e5 + 10);

map<int, int> s;
map<int, ll> dp;
ll solve(int pos, int h) {
	int g = tree.get2(pos, h);
	if (g == 0)
		return 1;
	if (g + s[g] < h)
		return 1;
	return dp[g];
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

	int h, w, n;
	cin >> h >> w >> n;

	vector<iii> vec(n);
	for(int i = 0; i < n; i++) {
		cin >> vec[i].first.first >> vec[i].second.first >> vec[i].second.second >> vec[i].first.second;
		s[vec[i].first.first] = vec[i].first.second;
	}

	sort(vec.begin(), vec.end());
	for(iii a : vec) {
		int l = a.second.first;
		int r = a.second.second;
		int h = a.first.first;
		tree.pre_add(l, r, h + a.first.second);
	}
	tree.make();
	for(iii a : vec) {
		int l = a.second.first;
		int r = a.second.second;
		int h = a.first.first;
		ll ans = 0;
		if(l == 1) {
			ans += solve(r + 1, h);
		} else {
			ans += solve(l - 1, h);
		}
		if(r == w) {
			ans += solve(l - 1, h);
		} else {
			ans += solve(r + 1, h);
		}
		if(ans >= MOD) {
			ans -= MOD;
		}
		dp[h] = ans;
		tree.upd(l, r, h, h + s[h]);
	}

	ll ans = 0;
	for(int i = 1; i <= w; i++) {
		ans += solve(i, h + 1);
	}

	cout << (ans % MOD) << endl;

}