#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
int discrete(T* a, int* b, int n) {
	vector<T> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int N = 18;
const int S = 1 << N;

typedef class TrieNode {
	public:
		vector<int> msk;
		TrieNode* ch[N + 1];

		void insert(int*, int, int);
} TrieNode;

TrieNode pool[400 * (N + 1)];
TrieNode *_top = pool;
TrieNode *tr = _top++;

void TrieNode::insert(int* a, int len, int s) {
	if (!len) {
		msk.push_back(s);
		return;
	}
	if (!ch[*a]) {
		ch[*a] = _top++;
	}
	ch[*a]->insert(a + 1, len - 1, s);		
}

int n;
bool G[N][N];
int bit[S];
ll f[S][N], g[N + 1][S], ans[S];

void fwt(ll* f, int n) {
	int N = 1 << n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < N; j++) {
			if ((j >> i) & 1) {
				f[j] += f[j ^ (1 << i)];
			}
		}
	}
}

void dfs(TrieNode* p, vector<ll> h) {
	if (!p->msk.empty()) {
		ll v = 0;
		for (int i = 0; i < (1 << n); i++) {
			v += ((bit[i] & 1) ? (-1) : 1) * h[i];
		}
		if (n & 1)
			v = -v;
		for (auto s : p->msk) {
			ans[s] += v;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		TrieNode* q = p->ch[i];
		if (!q) {
			continue;
		}
		vector<ll> nh = h;
		for (int j = 0; j < (1 << n); j++) {
			nh[j] *= g[i][j];
		}
		dfs(q, nh);
	}
}

int main() {
	static char foo[N + 3];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", foo);
		for (int j = 0; j < n; j++) {
			G[i][j] = foo[j] == '1';
		}
	}
	for (int i = 0; i < n; i++) {
		f[1 << i][i] = 1;
	}
	for (int s = 1; s < (1 << n); s++) {
		bit[s] = __builtin_popcount(s);
		for (int p = 0; p < n; p++) {
			ll v = f[s][p];
			if (!v) {
				continue;
			}
			g[bit[s]][s] += v;
			for (int q = 0; q < n; q++) {
				if (!((s >> q) & 1) && G[p][q]) {
					f[s | (1 << q)][q] += v;
				}
			}
		}
	}
	g[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		fwt(g[i], n);
	}
	for (int s = 0; s < (1 << (n - 1)); s++) {
		static vector<int> bar;
		int len = 1;
		bar.clear();
		for (int i = 0; i < n; i++) {
			if ((s >> i) & 1) {
				len++;
			} else {
				bar.push_back(len);
				len = 1;
			}
		}
		sort(bar.begin(), bar.end());
		tr->insert(bar.data(), bar.size(), s);
	}
	dfs(tr, vector<ll>(g[0], g[0] + (1 << n)));
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < (1 << (n - 1)); j++) {
			if (!((j >> i) & 1)) {
				ans[j] -= ans[j | (1 << i)];
			}
		}	
	}
	for (int i = 0; i < (1 << (n - 1)); i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}