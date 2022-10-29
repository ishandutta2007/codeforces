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

const int N = 250005;
 
typedef class SplayNode {
    public:
		int id;  
		boolean rev;
		SplayNode *fa, *ch[2];
 
        SplayNode() : id(0), rev(false) {   }
 
        boolean isroot() {
            return !fa || (fa->ch[0] != this && fa->ch[1] != this);
        }
        int which() {
            return isroot() ? -1 : fa->ch[1] == this;
        }
		void upd_rev() {
			swap(ch[0], ch[1]);
			rev ^= 1;
		}
		void push_down() {
			if (rev) {
				if (ch[0]) ch[0]->upd_rev();
				if (ch[1]) ch[1]->upd_rev();
				rev = 0;
			} 
		}
} SplayNode;
 
int uf[N];
int find(int x) {
	return (uf[x] == x) ? (x) : (uf[x] = find(uf[x]));
}
void unit(int x, int y){
	x = uf[x], y = uf[y];
	(x ^ y) && (uf[x] = y);
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
				pool[i].id = i;
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
 
        void access(SplayNode* p) {
            SplayNode* q = NULL;
            while (p) {
                splay(p);
                p->ch[1] = q;
                q = p, p = p->fa;
            }
        }
 
		void make_root(SplayNode* p) {
			access(p);
			splay(p);
			p->upd_rev();
		}

		void link(SplayNode* p, SplayNode* q) {
			make_root(p);
			access(q);
			splay(q);
			p->fa = q;
		}
		void cut(SplayNode* p, SplayNode* q) {
			make_root(p);
			access(q);
			splay(p);
			assert(p->ch[1] == q);
			p->ch[1] = q->fa = NULL;
		}

		void link(int x, int y) {
			link(pool + x, pool + y);
		}
		void cut(int x, int y) {
			cut(pool + x, pool + y);
		}

		pii find_edge(SplayNode* p, SplayNode* q) {
			make_root(p);
			access(q);
			splay(p);
			SplayNode *x = p, *y = NULL;
			int id = find(p->id);
			while (x) {
				x->push_down();
				if (find(x->id) == id) {
					y = x;
					x = x->ch[1];
				} else {
					x = x->ch[0];
				}
			}
			assert(y);
			splay(x = y);
			x = x->ch[1];
			while (x->ch[0])
				x->push_down(), x = x->ch[0];
			splay(x);
			return pii(x->id, y->id);
		}
		pii find_edge(int x, int y) {
			return find_edge(pool + x, pool + y);
		}
} LinkCutTree;

int n;

typedef class Tree {
	public:
		int fa[N];
		vector<int> G[N];
		vector<int> tour;

		void dfs(int p, int fa) {
			this->fa[p] = fa;
			for (auto e : G[p]) {
				if (e ^ fa) {
					dfs(e, p);
				}
			}
			tour.push_back(p);
		}

		void init() {
			for (int i = 1, u, v; i < n; i++) {
				scanf("%d%d", &u, &v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
			dfs(1, 0);
		}
} Tree;

Tree tr1, tr2;
LinkCutTree lct;

int main() {
	scanf("%d", &n);
	tr1.init();
	tr2.init();
	lct.init(n, tr2.fa);
	printf("%d\n", n - 1);
	auto& tour = tr1.tour;
	tour.pop_back();
	for (int i = 1; i <= n; i++)
		uf[i] = i;
	for (auto x : tour) {
		int fx = tr1.fa[x];
		pii eb = lct.find_edge(x, fx);
		int c = eb.first, d = eb.second;
		printf("%d %d %d %d\n", x, fx, c, d);
		lct.cut(c, d);
		lct.link(x, fx);
		unit(x, fx);
	}
	return 0;
}