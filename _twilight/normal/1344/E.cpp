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

#define ll long long

const int N = 1e5 + 5;
const int bzmax = 19;

typedef class SplayNode {
    public:
		int c, tg;
		SplayNode *fa, *ch[2];
 
        SplayNode() : c(0), tg(0) {   }
 
        boolean isroot() {
            return !fa || (fa->ch[0] != this && fa->ch[1] != this);
        }
        int which() {
            return isroot() ? -1 : fa->ch[1] == this;
        }
		void upd(int v) {
			c = tg = v;
		}
		void push_down() {
			if (tg) {
				if (ch[0]) ch[0]->upd(tg);
				if (ch[1]) ch[1]->upd(tg);
				tg = 0;
			}
		}
} SplayNode;
 
int n, m;
vector<int> G[N];
int fa[N];
ll dep[N];
int bz[N][bzmax];
void dfs(int p, int fa) {
	bz[p][0] = fa;
	::fa[p] = fa;
	dep[p] += dep[fa];
	for (int i = 1; i < bzmax; i++) {
		bz[p][i] = bz[bz[p][i - 1]][i - 1];
	}
	for (auto e : G[p]) {
		dfs(e, p);
	}
}
int get(int p, int q) {
	for (int i = bzmax; i--; ) {
		if (dep[bz[p][i]] > dep[q]) {
			p = bz[p][i];
		}	
	}
	return p;
}

typedef class LinkCutTree {
    public:
        SplayNode* pool;
 
        void init(int n, int* fa) {
            pool = new SplayNode[(n + 1)];
            for (int i = 1; i <= n; i++) {
                pool[i].ch[0] = pool[i].ch[1] = NULL;
                if (fa[i]) {
					pool[i].fa = pool + fa[i];
				} else {
					pool[i].fa = NULL;
				}
			}
        }
 
        void rotate(SplayNode* p) {
            int d = p->which();
            int df = p->fa->which();
            SplayNode* fa = p->fa;
            fa->ch[d] = p->ch[d ^ 1];
            p->ch[d ^ 1] = fa;
            if (~df)
                fa->fa->ch[df] = p;
            p->fa = fa->fa;
            fa->fa = p;
            if (fa->ch[d])
                fa->ch[d]->fa = fa;
        }
 
        void splay(SplayNode* p) {
			static SplayNode* stk[N];
			SplayNode** top = stk;
			for (SplayNode *q = p; *(++top) = q, !q->isroot(); q = q->fa);
			for ( ; top != stk; (*top--)->push_down());
			for ( ; !p->isroot(); rotate(p)) {
                if (!p->fa->isroot()) {
                    rotate((p->which() == p->fa->which()) ? (p->fa) : (p));
                }
            }
        }
 
        vector<int> access(SplayNode* p) {
            SplayNode* q = NULL;
            vector<int> rt;
			while (p) {
                rt.push_back(p - pool);
				splay(p);
				p->ch[1] = q;
				q = p, p = p->fa;
            }
			return rt;
        }
		vector<int> access(int p) {
			return access(pool + p);
		}

		void cover(int _p, int v) {
			SplayNode* p = pool + _p;
			splay(p);
			p->upd(v);
		}
		int get_t(int _p) {
			SplayNode* p = pool + _p;
			splay(p);
			return p->c;
		}
} LinkCutTree;

int to[N];
LinkCutTree lct;

vector<pair<ll, ll>> cts;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v, d; i < n; i++) {
		cin >> u >> v >> d;
		G[u].push_back(v);
		dep[v] = d;
		to[u] = v;
	}
	dfs(1, 0);
	lct.init(n, fa);
	for (int i = 1, p, t; i <= m; i++) {
		cin >> p >> t;
		if (p == 1) continue;
		vector<int> ps = lct.access(p);
		reverse(ps.begin(), ps.end());
		ps.pop_back();
//		cerr << "qwq: ";
		for (auto q : ps) {
			int nx = get(p, q);
			if (nx ^ to[q]) {
//				cerr << q << " ";
				to[q] = nx;
				int told = lct.get_t(q);
				if (told) {
					cts.push_back(make_pair(told + dep[q] + 1, t + dep[q]));
				} else {
					cts.push_back(make_pair(1, t + dep[q]));
				}
			}
		}
		lct.access(fa[p]);
//		cerr << '\n';
		lct.cover(1, t);
	}
	sort(cts.begin(), cts.end(), [&] (pair<ll, ll> a, pair<ll, ll> b) {	return a.sc < b.sc;	});
//	cerr << cts << '\n';
	set<ll> sf, so;
	ll ans1 = -1;
	for (auto x : cts) {
		sf.insert(x.fi);
	}
	for (auto x : cts) {
		auto it = sf.lower_bound(x.fi);
		if (it == sf.end() || *it > x.sc) {
			ans1 = x.sc;
			break;
		}
		so.insert(*it);
		if (!so.count(*it + 1))
			sf.insert(it, *it + 1);
		sf.erase(it);
	}
	if (ans1 < 0) {
		cout << -1 << " " << cts.size() << '\n';
	} else {
		int ans = 0;
		for (auto x : cts)
			ans += x.sc < ans1;
		cout << ans1 << " " << ans << '\n';
	}
	return 0;
}