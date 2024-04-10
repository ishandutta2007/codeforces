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

template <class T> int get_pos(vector<T>& v, T x) {
    return lower_bound(all(v), x) - v.begin();
}

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
        sum[ind] += (R - L + 1) * lazy[ind];
        if (L != R) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    void pull(int ind) {
        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
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

    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
    }
};

const int INF = 1.5e9;
const int INF2 = 1e9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    LazySeg<int> seg; seg.init(n);
    seg.upd(0, n - 1, INF);
    auto query = [&](int l, int r) -> int {
        cout << "? " <<  l + 1 << " " << r + 1 << endl;
        int res; cin >> res;
        res = (r - l + 1) - res;
        return res;
    };
    auto answer = [&](int x) {
        cout << "! " << x + 1 << endl;
    };
    auto get = [&](int x) -> int {
        int res = seg.qsum(x, x);
        if (res < INF2) return res;
        int nxt = query(0, x);
        seg.upd(x, x, nxt - res);
        return nxt;
    };
    f0r(turn, t) {
        int k; cin >> k;
        int lo = 0;
        int hi = n - 1;
        int loc = -1;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;
            int v = get(mid);
            if (v == k) {
                hi = mid;
            } else if (v < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (loc == -1) {
            if (get(lo) == k) {
                loc = lo;
            } else {
                loc = hi;
            }
        }
        answer(loc);
        seg.upd(loc, n - 1, -1);
    }
    return 0;
}

/**
 * guess the kth 1
 * it turns into 0
 */