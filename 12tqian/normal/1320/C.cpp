#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }
template<class T, int SZ> struct LazySeg {
    T mx[2 * SZ], lazy[2 * SZ];
    LazySeg() {
        for (int i = 0; i < 2 * SZ; i++) {
            mx[i] = 0;
            lazy[i] = 0;
        }
    }
    void push(int ind, int L, int R) {
        mx[ind] += lazy[ind];
        if (L != R) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    void pull(int ind) {
        mx[ind] = max(mx[2 * ind], mx[2 * ind + 1]);
    }
    void build() {
        for (int i = SZ - 1; i >= 1; i--) {
            pull(i);
        }
    }
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }
    T qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (lo > R || L > hi) return -1e18;
        if (lo <= L && R <= hi) return mx[ind];
        int M = (L + R) / 2;
        return max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind + 1, M + 1, R));
    }
};
int main() {
    const int INF = 2e9;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<array<ll, 2>> we(n);
    vector<array<ll, 2>> ar(m);
    vector<array<ll, 3>> mo(p);
    set<int> xs;
    set<int> ys;
    map<int, int> mx;
    map<int, int> my;
    for (int i = 0; i < n; i++) {
        cin >> we[i][0] >> we[i][1];
        xs.insert(we[i][0]);
    }
    for (int i = 0; i < m; i++) {
        cin >> ar[i][0] >> ar[i][1];
        ys.insert(ar[i][0]);
    }
    for (int i = 0; i < p; i++) {
        cin >> mo[i][0] >> mo[i][1] >> mo[i][2];
    }
    int cnt = 0;
    xs.insert(INF);
    ys.insert(INF);
    for (int x : xs) {
        mx[x] = cnt;
        cnt++;
    }
    cnt = 0;
    for (int y : ys) {
        my[y] = cnt;
        cnt++;
    }
    vector<array<ll, 3>> events;
    for (int i = 0; i < n; i++) {
        events.push_back({mx[we[i][0]], INF, we[i][1]});
    }
    for (int i = 0; i < p; i++) {
        events.push_back({mx[*xs.upper_bound(mo[i][0])], my[*ys.upper_bound(mo[i][1])], mo[i][2]});
    }
    map<int, int> best;
    for (int i = 0; i < m; i++) {
        int y = my[ar[i][0]];
        int cost = ar[i][1];
        if (best.find(y) == best.end()) {
            best[y] = cost;
        } else {
            best[y] = min(best[y], cost);
        }
    }
    sort(events.begin(), events.end());
    const int SZ = (1 << 20);
    LazySeg<ll, SZ> seg;
    for (auto use : best) {
        int y = use.first;
        seg.upd(y, y, -use.second);
    }
    seg.upd(my[INF], my[INF], -INF);
    ll ans = -1e18;
    for (auto e : events) {
        if (e[1] == INF) {
            ans = max(ans, seg.qmax(0, (int) ys.size() - 1) - e[2]);
        } else {
            seg.upd(e[1], SZ - 1, e[2]);
        }
    }
    cout << ans << '\n';
    return 0;
}