/**
 *    author:  otera
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using int128_t = __int128_t;
#define repa(i, n) for(int i = 0; i < n; ++ i)
#define repb(i, a, b) for(int i = a; i < b; ++ i)
#define repc(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= n; ++ i)
#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)
#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define rev_repa(i, n) for(int i=n-1;i>=0;i--)
#define rev_repb(i, a, b) assert(a > b);for(int i=a;i>b;i--)
#define rev_rep(...) overload3(__VA_ARGS__, rev_repb, rev_repa)(__VA_ARGS__)
#define rev_rep1a(i, n) for(int i=n;i>=1;i--)
#define rev_rep1b(i, a, b) assert(a >= b);for(int i=a;i>=b;i--)
#define rev_rep1(...) overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(), c.rend()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define kth_bit(x, k) ((x>>k)&1)
#define unless(A) if(!(A))
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T, class U> using umap = unordered_map<T, U>;
template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ cout << ' '; }
template<class T> void print(const T& a){ cout << a; }
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }
int out(){ cout << '\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0; }
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#define dump(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...)
#define dump(...)
#endif

struct io_setup {
    io_setup(int precision = 20) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(precision);
    }
} io_setup_ {};

void solve() {
    INT(n, k);
    vvc<int> g(n);
    vc<int> par(n, -1);
    for(int i = 1; i < n; ++ i) {
        in(par[i]); -- par[i];
        g[i].eb(par[i]);
        g[par[i]].eb(i);
    }
    vc<int> dep(n, -1);
    auto dfs = [&](auto&&dfs, int v, int p, int d) -> void {
        dep[v] = d;
        for(int nv: g[v]) {
            if(nv == p) continue;
            dfs(dfs, nv, v, d + 1);
        }
    };
    dfs(dfs, 0, -1, 0);
    int dma = 0, t = 0;
    rep(i, n) {
        if(chmax(dma, dep[i])) {
            t = i;
        }
    }
    vc<int> cand;
    int now = t;
    cand.eb(now);
    while(now != 0) {
        now = par[now];
        cand.eb(now);
    }
    Rev(cand);
    vc<int> ok(n, 0);
    vc<int> check(n, 0);
    int sz = si(cand);
    dump(cand);
    int res = k;
    queue<int> que;
    int len = 0;
    int fi = -1;
    rep(i, min(sz, k)) {
        ok[cand[i]] = 1;
        check[cand[i]] = 1;
        fi = cand[i];
        -- res;
        if(i != 0) ++ len;
    }
    rep(i, n) {
        if(ok[i]) {
            for(int nv: g[i]) {
                if(!ok[nv]) {
                    que.push(nv);
                }
            }
        }
    }
    while(res > 0 and si(cand)) {
        int v = que.front(); len += 2; que.pop(); -- res;
        ok[v] = 1;
        for(int nv: g[v]) {
            if(!ok[nv]) {
                que.push(nv);
            }
        }
    }
    rep(i, n) {
        sort(all(g[i]), [&](int u, int v) {
            return check[u] < check[v];
        });
    }
    out(len);
    vc<int> ans;
    bool end = 0;
    debug(fi);
    auto dfs2 = [&](auto&&dfs2, int v, int p) -> void {
        if(end) return;
        ans.eb(v);
        for(int nv: g[v]) {
            if(nv == p) continue;
            if(ok[nv]){
                dfs2(dfs2, nv, v);
                if(!end) ans.eb(v);
            }
        }
        if(end) return;
        if(v == fi) {
            end = 1;
            return;
        }
    };
    dfs2(dfs2, 0, -1);
    for(int &x: ans) ++ x;
    out(ans);
}

signed main() {
    int testcase = 1;
    in(testcase);
    while(testcase--) solve();
    return 0;
}