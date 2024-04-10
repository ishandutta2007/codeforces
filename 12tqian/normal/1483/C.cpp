#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T> struct SparseTable {
    std::vector<T> v;
    std::vector<std::vector<int>> jump;

    int level(int x) { return 31 - __builtin_clz(x); }

    int comb(int a, int b) {
        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
    }

    void init(const std::vector<T>& _v) {
        v = _v;
        jump = {std::vector<int>((int)v.size())};
        iota(jump[0].begin(), jump[0].end(), 0);
        for (int j = 1; (1 << j) <= (int)v.size(); j++) {
            jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
            for (int i = 0; i < (int)jump[j].size(); i++) {
                jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int index(int l, int r) {
        assert(l <= r);
        int d = level(r - l + 1);
        return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
    }

    T query(int l, int r) {
        return v[index(l, r)];
    }
};

const ll INF = 1e18;

template <class T> struct LazySeg {
    std::vector<T> sum, lazy;
    int sz;

    void init(int sz_) {
        sz = 1;
        while (sz < sz_) sz *= 2;
        sum.assign(2 * sz, 0);
        lazy.assign(2 * sz, 0);
    }

    void push(int ind, int L, int R) {
        sum[ind] += lazy[ind];
        if (L != R) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    void pull(int ind) {
        sum[ind] = max(sum[2 * ind], sum[2 * ind + 1]);
    }

    void build() {
        for (int i = sz - 1; i >= 1; i--) {
            pull(i);
        }
    }

    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
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

    T qmax(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (lo > R || L > hi) return -INF;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind + 1, M + 1, R));
    }
};

const int N = 3e5 + 5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi h(n);
    vl b(n);
    vl dp(n);
    LazySeg<ll> seg;
    seg.init(n);
    f0r(i, n) cin >> h[i], h[i]--;
    f0r(i, n) cin >> b[i];
    SparseTable<int> RQ;
    RQ.init(h);
    auto value = [&](int l, int r) -> ll {
        return b[RQ.index(l, r)];
    };
    vi active;
    f0r(i, n) {
        while (sz(active)) {
            int x = active.back();
            if (h[x] > h[i]) {
                active.pop_back();
                int go;
                if (sz(active) == 0) {
                    go = 0;
                } else {
                    go = active.back();
                }
                seg.upd(go, x - 1, -b[x]);
            } else {
                break;
            }
        }
        int go;
        if (sz(active) == 0) {
            go = 0;
        } else {
            go = active.back();
        }
        // cout << go <<  " " << i << endl;
        seg.upd(go, i - 1, b[i]);
        dp[i] = max(seg.qmax(0, i - 1), value(0, i));
        // cout << dp[i] << '\n';
        seg.upd(i, i, dp[i]);
        active.pb(i);
    }
    cout << dp[n - 1] << '\n';

    return 0;
}

/**
 * active means form that point to the previous point
 */