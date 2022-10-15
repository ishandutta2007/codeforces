#include <bits/stdc++.h>
using namespace std;
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
char wwww[12];
int kkkk;
inline void write(int x) {
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
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct segment_tree {
private:
	int *t, n;
	void build(int v, int l, int r) {
		t[v] = INT_MAX;
		if (l == r) {
			return;
		}
		int x = (l + r) >> 1;
		build(v << 1, l, x);
		build(v << 1 | 1, x + 1, r);
	}
	int get_min(int v, int tl, int tr, int l, int r) {
		if (l <= tl && tr <= r)
			return t[v];
		if (tr < l || r < tl)
			return INT_MAX;
		int x = (tl + tr) >> 1;
		return min(get_min(v << 1, tl, x, l, r),
				get_min(v << 1 | 1, x + 1, tr, l, r));
	}
	void upd(int v, int l, int r, int pos, int val) {
		if (l == r) {
			t[v] = val;
			return;
		}
		int x = (l + r) >> 1;
		if (pos <= x)
			upd(v << 1, l, x, pos, val);
		else
			upd(v << 1 | 1, x + 1, r, pos, val);
		t[v] = min(t[v << 1], t[v << 1 | 1]);
	}
public:
	segment_tree(int n) {
		t = new int[n << 2];
		this->n = n;
		build(1, 0, n - 1);
	}
	void upd(int pos, int val) {
		upd(1, 0, n - 1, pos, val);
	}
	int get_min(int l, int r) {
		if (r < l)
			return INT_MAX;
		return get_min(1, 0, n - 1, l, r);
	}
};

const int MAX = 1e5 + 14;

vector<int> vec[MAX];
bool is_root[MAX];
int n, m;
int present[MAX];
int parent[MAX];
vector<int> ans;
int timer = 0;
int tin[MAX], tout[MAX], h[MAX];
bool added[MAX], need_add[MAX];
segment_tree *tree;

bool now[MAX];

void add(int pos) {
	if (!added[pos]) {
		added[pos] = true;
		ans.push_back(pos);
	}
}

vector<int> q;
bool are_needed[MAX];
int where[MAX];

void dfs1(int pos, int hh) {
	for (int i = 0; i < (int) vec[pos].size(); i++)
		dfs1(vec[pos][i], hh + 1);
	if (are_needed[pos]) {
		where[pos] = q.size();
		q.push_back(pos);
		ans.push_back(pos);
	}
}

void sorry() {
	cout << -1 << endl;
	exit(0);
}

set<pair<int, int> > w;

void dfs2(int pos) {
	if (are_needed[pos]) {
		w.insert(make_pair(where[pos], pos));
	}
	for (int i = 0; i < (int) vec[pos].size(); i++)
		dfs2(vec[pos][i]);
	if(w.empty())
		sorry();
	if(w.begin()->second != present[pos])
		sorry();
	if (are_needed[pos]) {
		::w.erase(make_pair(where[pos], pos));
	}
}

int main() {

	cout.precision(3);
	cout << fixed;
	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;

#else

#endif

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		is_root[i] = true;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		parent[b] = a;
		is_root[b] = false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> present[i];
		are_needed[present[i]] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (is_root[i]) {
			timer = 0;
			dfs1(i, 1);
			dfs2(i);
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << endl;

}