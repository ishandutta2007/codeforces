//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
const long double PI = 4 * atan((long double) 1);
 
typedef long long ll;
typedef long double ld;
typedef double db;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)
#define resz resize
#define ins insert
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
 
template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);
 
	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t); re(ts...);
	}
 
	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
 
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
 
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
		pr(t); pr(ts...);
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) {
		pr("{",x.f,", ",x.s,"}");
	}
	template<class T> void pr(const T& x) {
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
		pr("}");
	}
 
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
	}
 
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}
 
using namespace output;
 
namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
 
using namespace io;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 998244353, root = 3;
 
typedef decay<decltype(MOD)>::type T;
struct mi {
	T val;
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) {
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
 
	friend bool operator==(const mi& a, const mi& b) {
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) {
		return a.val < b.val; }
 
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) {
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
 
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
 
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
 
 
typedef complex<db> cd;
typedef vector<cd> vcd;
 
struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return splitmix64(x ^ FIXED_RANDOM);
    }
};
 
template<typename T_pair>
struct safe_pair32_hash {
    size_t operator()(const T_pair &x) const {
        assert(sizeof(x.first) <= 4 && sizeof(x.second) <= 4);
        static safe_hash hash_obj;
        return hash_obj(((uint64_t) x.first << 32) ^ x.second);
    }
};
 
const int INF = 1e9 + 5;

 
struct dynamic_connectivity {
    struct undo_op {
        int x, y, y_parent;
 
        undo_op(int _x = -INF, int _y = -INF, int _y_parent = -INF) : x(_x), y(_y), y_parent(_y_parent) {}
    };
 
    struct dc_union_find {
        vector<int> parent;
        vector<pair<int, int>> size;
        long long combined = 0;
 
        dc_union_find(int n = 0) {
            if (n > 0)
                init(n);
        }
 
        void init(int n) {
            parent.resize(2 * n);
            size.resize(2 * n);
            combined = 0;
 
            for (int i = 0; i < 2 * n; i++) {
                parent[i] = i;
                size[i] = i < n ? make_pair(1, 0) : make_pair(0, 1);
            }
        }
 
        int find(int x) {
            while (x != parent[x])
                x = parent[x];
 
            return x;
        }
 
        int size_sum(int x) const {
            return size[x].first + size[x].second;
        }
 
        bool unite(int x, int y, vector<undo_op> &undo_ops) {
            x = find(x);
            y = find(y);
 
            if (x == y)
                return false;
 
            if (size_sum(x) < size_sum(y))
                swap(x, y);
 
            undo_ops.emplace_back(x, y, parent[y]);
            parent[y] = x;
            combined += (long long) size[x].first * size[y].second + (long long) size[y].first * size[x].second;
            size[x].first += size[y].first;
            size[x].second += size[y].second;
            return true;
        }
 
        void undo(const undo_op &op) {
            size[op.x].first -= size[op.y].first;
            size[op.x].second -= size[op.y].second;
            combined -= (long long) size[op.x].first * size[op.y].second + (long long) size[op.y].first * size[op.x].second;
            parent[op.y] = op.y_parent;
        }
    };
 
    struct query {
        // type = +1: add, type = -1: erase, type = 0: answer
        int type, x, y, other_index;
 
        query(int _type = -INF, int _x = -INF, int _y = -INF, int _other_index = INF)
            : type(_type), x(_x), y(_y), other_index(_other_index) {}
    };
 
    vector<query> queries;
    gp_hash_table<pair<int, int>, int, safe_pair32_hash<pair<int, int>>> seen_table;
    dc_union_find UF;
    vector<undo_op> undo_ops;
    vector<long long> answers;
 
    void recurse(int start, int end) {
        if (end - start <= 1) {
            if (end - start == 1 && queries[start].type == 0)
                answers.push_back(UF.combined);
 
            return;
        }
 
        int mid = (start + end) / 2;
        size_t initial_size = undo_ops.size();
 
        for (int i = mid; i < end; i++)
            if (queries[i].type == -1 && queries[i].other_index < start)
                UF.unite(queries[i].x, queries[i].y, undo_ops);
 
        recurse(start, mid);
 
        while (undo_ops.size() > initial_size) {
            UF.undo(undo_ops.back());
            undo_ops.pop_back();
        }
 
        for (int i = start; i < mid; i++)
            if (queries[i].type == +1 && queries[i].other_index >= end)
                UF.unite(queries[i].x, queries[i].y, undo_ops);
 
        recurse(mid, end);
 
        while (undo_ops.size() > initial_size) {
            UF.undo(undo_ops.back());
            undo_ops.pop_back();
        }
    }
 
    void add_query() {
        queries.emplace_back(0);
    }
 
    void add_edge_op(int x, int y) {
        if (x > y)
            swap(x, y);
 
        if (seen_table.find({x, y}) == seen_table.end()) {
            seen_table[{x, y}] = queries.size();
            queries.emplace_back(+1, x, y, INF);
        } else {
            int index = seen_table[{x, y}];
            seen_table.erase({x, y});
            queries[index].other_index = queries.size();
            queries.emplace_back(-1, x, y, index);
        }
    }
 
    vector<long long> solve(int n) {
        UF.init(n);
        recurse(0, queries.size());
        return answers;
    }
};
const int MAX = 3e5 + 5;
int main(){
	setIO("");
	int q;
	re(q);
	dynamic_connectivity dc;
	f0r(i, q){
		int x, y;
		re(x,y);
		x--; y--;
		dc.add_edge_op(x, y+MAX);
		dc.add_query();
	}
	auto res = dc.solve(MAX);
	f0r(i, q){
		ps(res[i]);
	}
	return 0;
}