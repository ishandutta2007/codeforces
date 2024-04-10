#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

#define hashmap unordered_map
#define hashset unordered_set


using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif


typedef struct node* pnode;
typedef int key;

pnode null = nullptr;

struct node {
    key k;
    int add = 0;
    int x = gen();
    int cnt = 1;
    pnode l = null, r = null, p = null;
    node(key _k) : k(_k) {}
};

void print(pnode t) {
    if (t == null) return;
    print(t->l, t->k, ' ', t->r);
}

pnode newnode(const key &k) {
    return new node(k);
}

inline int getcnt(pnode n) {
    return n == null ? 0 : n->cnt;
}

inline void updparent(pnode son, pnode parent) {
    if (son != null) {
        son->p = parent;
    }
}

inline void upd(pnode n) {
    if (n) {
        n->cnt = 1 + getcnt(n->l) + getcnt(n->r);
        updparent(n->l, n);
        updparent(n->r, n);
    }
}

inline void adder(pnode n, int val) {
	if (n) {
		n->k += val;
		n->add += val;
	}
}

inline void push(pnode n) {
	if (n) {
		adder(n->l, n->add);
		adder(n->r, n->add);
		n->add = 0;
	}
}

pnode merge(pnode a, pnode b) {
	push(a);
	push(b);
    if (a == null) return b;
    if (b == null) return a;
    if (a->x > b->x) {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

void splitind(pnode t, int ind, pnode &l, pnode &r) {
	push(t);
    if (t == null) return void(l = r = null);
    if (getcnt(t->l) >= ind) {
        splitind(t->l, ind, l, t->l);
        r = t;
    } else {
        splitind(t->r, ind - getcnt(t->l) - 1, t->r, r);
        l = t;
    }
    upd(l);
    upd(r);
}

void splitval(pnode t, const key &k, pnode &l, pnode &r) {
	push(t);
    if (t == null) return void(l = r = null);
    if (k < t->k) {
        splitval(t->l, k, l, t->l);
        r = t;
    } else {
        splitval(t->r, k, t->r, r);
        l = t;
    }
    upd(l);
    upd(r);
}

void splitvalup(pnode t, const key &k, pnode &l, pnode &r) {
	push(t);
    if (t == null) return void(l = r = null);
    if (!(t->k < k)) {
        splitval(t->l, k, l, t->l);
        r = t;
        updparent(r, null);
    } else {
        splitval(t->r, k, t->r, r);
        l = t;
        updparent(l, null);
    }
    upd(l);
    upd(r);
}

void insert(pnode &t, const key &k) {
	push(t);
    pnode r;
    splitval(t, k, t, r);
    t = merge(t, newnode(k));
    t = merge(t, r);
}

void insert(pnode &t, int ind, const key &k) {
	push(t);
    pnode r;
    splitind(t, ind, t, r);
    t = merge(t, newnode(k));
    t = merge(t, r);
}

key min(pnode t) {
	push(t);
    assert(t != null);
    if (t->l != null) return min(t->l);
    return t->k;
}

key max(pnode t) {
	push(t);
    assert(t != null);
    if (t->r != null) return max(t->r);
    return t->k;
}

void eraseone(pnode &t, const key &k) {
	push(t);
    pnode r;
    splitval(t, k, t, r);
    assert(min(r) == k);
    pnode m;
    splitind(r, 1, m, r);
    t = merge(t, r);
}

void eraseall(pnode &t, const key &k) {
	push(t);
    pnode m, r;
    splitval(t, k, t, r);
    splitvalup(r, k, m, r);
    t = merge(t, r);
}

key kth(pnode t, int ind) {
	push(t);
    assert(ind >= 0 && ind < getcnt(t));
    if (ind == getcnt(t->l)) return t->k;
    if (ind < getcnt(t->l)) return kth(t->l, ind);
    return kth(t->r, ind - getcnt(t->l) - 1);
}

int lower_bound(pnode t, const key &k) {
	push(t);
    if (t == null) return 0;
    if (!(t->k < k)) return lower_bound(t->l, k);
    return lower_bound(t->r, k) + 1 + getcnt(t->l);
}

int upper_bound(pnode t, const key &k) {
	push(t);
    if (t == null) return 0;
    if (k < t->k) return upper_bound(t->l, k);
    return upper_bound(t->r, k) + 1 + getcnt(t->l);
}

int getind(pnode t) {
	push(t);
    assert(t != null);
    int ans = 1 + getcnt(t->l);
    pnode was = t;
    t = t->p;
    while (t != null) {
        if (t->l != was)
            ans += getcnt(t->l) + 1;
        was = t;
        t = t->p;
    }
    return ans;
}

struct zet {
    int val;
    explicit operator int() const { return val; }
    zet(ll x = 0) { val = (x >= -mod && x < mod ? x : x % mod); if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
    friend bool operator<(zet const &a, zet const &b) { return a.val < b.val; }
};




ll n, mv;
vector<pii> v;
bool viv = false;


void printer(pnode root) {
	cout << "\tnow: ";
	print(root);
	cout << endl;

}


const int K = ml / 2;
vector<zet> f, fi;

void prepare() {
	f.resize(K, 1);
	for (int i = 1; i < K; i++)
		f[i] = f[i - 1] * i;
	// fi.resize(K);	
	// for (int i = 0; i < f.size(); i++)
	// 	fi[i] = inv(f[i]);
}

zet C(int n, int k) {
	zet ans = f[n];
	ans /= f[k];
	ans /= f[n - k];
	return ans;
}

void solve() {
	cin >> n >> mv;
	v.resize(mv);
	for (auto &p : v)
		cin >> p.F >> p.S, p.F--, p.S--;
	int nx = 0;
	set<pii> seg;
	seg.insert({0, 1});

	auto root = newnode(0);
	// printer(root);
	for (auto p : v) {
		int pl = p.S;
		// cout << "WORK " << pl << endl;
		pnode l, r;
		splitval(root, pl - 1, l, r);
		adder(r, 1);
		root = merge(l, r);	
		// cout << "\t\t\t";
		// printer(root);
		int pl_l = lower_bound(root, pl + 1);	
		int val = -1;
		if (pl_l < root->cnt)
			val = kth(root, pl_l);
		if (val != pl + 1) {
			// cout << "\t";
			// printer(root);
			// cout << "\t\tlower_bound = " << val << endl;
			insert(root, pl + 1);
		}
		if (pl == 0)
			insert(root, 0);
		// cout << "\tget = ";
		// printer(root);
	}
	int vals = root->cnt;
	int add = n - vals;

	zet ans = C(n + add, add);
	cout << ans.val << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prepare();
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}