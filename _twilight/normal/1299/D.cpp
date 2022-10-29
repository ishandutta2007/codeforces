#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

const int N = 1e5 + 5;

typedef class LinearBasis {
	public:
		int a[5];

		boolean insert(int x) {
			for (int i = 4; ~i && x; i--) {
				if ((x >> i) & 1)
					x ^= a[i];
				if ((x >> i) & 1) {
					a[i] = x;
					return true;
				}
			}
			return false;
		}
		boolean sinsert(int x) {
			for (int i = 4; ~i && x; i--) {
				if ((x >> i) & 1)
					x ^= a[i];
				if ((x >> i) & 1) {
					a[i] = x;
					for (int j = i - 1; ~j; j--)
						if ((a[i] >> j) & 1)
							a[i] ^= a[j];
					for (int j = i + 1; j < 5; j++)
						if ((a[j] >> i) & 1)
							a[j] ^= a[i];
					return true;
				}
			}
			return false;
		}
		boolean empty() {
			return !(a[0] || a[1] || a[2] || a[3] || a[4]);
		}
} LinearBasis;

#define pii pair<int, int>

const int Mod = 1e9 + 7;

const int inv3 = (Mod + 1) / 3;

int add(int x, int y) {
	return ((x += y) >= Mod) ? (x -= Mod) : x; 
}

#define ws wss

int n, m;
int uf[N];
int acw[N];
int dep[N];
boolean can[N];
LinearBasis lb[N];
vector<int> ws[N];
vector<pii> G[N];

int find(int x) {
	return (x ^ uf[x]) ? (uf[x] = find(uf[x])) : x;
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if (x ^ y) {
		uf[x] = y;
	}
}

int dfn[N];
void dfs(int p, int fa, LinearBasis& lb, boolean &can) {
	static int dfc = 0;
	dfn[p] = ++dfc;
	for (auto _ : G[p]) {
		int e = _.first;
		int w = _.second;
		if (e == fa || e == 1)
			continue;
		if (dfn[e]) {
			if (dfn[p] < dfn[e])
				can = can && lb.sinsert(dep[p] ^ dep[e] ^ w);
		} else {
			dep[e] = dep[p] ^ w;
			dfs(e, p, lb, can);
		}
	}
}

typedef class TrieNode {
	public:
		int c;
		map<int, TrieNode*> ch;

		void insert(int*, int, int);
} TrieNode;

TrieNode pool[N << 2];
TrieNode *_top = pool + 1;
TrieNode *rt = pool;

void TrieNode::insert(int* a, int d, int v = 1) {
	if (d == 5) {
		c = add(c, v);
		return;
	}
	if (!*a) {
		insert(a + 1, d + 1, v);
	} else {
		if (!ch.count(*a)) {
			(ch[*a] = _top++)->insert(a + 1, d + 1, v);
		} else {
			ch[*a]->insert(a + 1, d + 1, v);
		}
	}
}

int ans = 0;
void dfs(LinearBasis lb, TrieNode* p, int c, int fr) {
	if (!c)
		return;
	if (p->c) {
		ans = (ans + 1ll * c * p->c % Mod) % Mod;
		dfs(lb, rt, 1ll * c * p->c % Mod, fr);
	}
	for (auto par : p->ch) {
		int w = par.first;
		int nfr = fr;
		if (p == rt) {
			if (w <= fr)
				continue;
			nfr = w;
		}
		TrieNode* q = par.second;
		LinearBasis la = lb;
		if (la.insert(w)) {
			dfs(la, q, c, nfr);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
		acw[i] = -1;
	}
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		if (u > v)
			swap(u, v);
		if (u ^ 1)
			unit(u, v);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	vector<boolean> inc (n + 1, false);
	for (auto par : G[1]) {
		int e = par.first;
		int w = par.second;
		inc[e] = true;
		ws[find(e)].push_back(w);
		for (auto _ : G[e]) {
			int p = _.first;
			int w1 = _.second;
			if (inc[p]) {
				acw[find(e)] = w1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (find(i) == i) {
			can[i] = true;
			dfs(i, 1, lb[i], can[i]);
		}
	}
	int coef = 1;
	for (int i = 2; i <= n; i++) {
		if (find(i) ^ i)
			continue;
		if (!can[i])
			continue;
		LinearBasis &lb = ::lb[i];
		if (~acw[i]) {
			boolean aflag = lb.empty();
			if (aflag) {
				coef = 1ll * coef * 3 % Mod;
			} else {
				rt->insert(lb.a, 0, 2);
			}
			if (~acw[i] && lb.sinsert(acw[i] ^ ws[i][0] ^ ws[i][1])) {
				rt->insert(lb.a, 0, (aflag) ? (inv3) : 1);
			}
		} else {
			if (lb.empty()) {
				coef = (coef << 1) % Mod;
			} else {
				rt->insert(lb.a, 0);
			}
		}
	}
	dfs(LinearBasis(), rt, 1, -1);
	ans = 1ll * (ans + 1) * coef % Mod;
	cout << ans << '\n';
	return 0;
}