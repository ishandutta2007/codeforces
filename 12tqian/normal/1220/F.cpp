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
#define sz(x) (int) (x).size()
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
    
template <class T> struct MaxSparseTable {
    std::vector<T> v;
    std::vector<std::vector<int>> jump;

    int level(int x) { return 31 - __builtin_clz(x); }

    int comb(int a, int b) {
        return v[a] == v[b] ? std::min(a, b) : (v[a] > v[b] ? a : b);
    }

    void init(const std::vector<T>& _v) {
        v = _v;
        jump = {std::vector<int>((int) v.size())};
        iota(jump[0].begin(), jump[0].end(), 0);
        for (int j = 1; (1 << j) <= (int) v.size(); j++) {
            jump.push_back(std::vector<int>((int) v.size() - (1 << j) + 1));
            for (int i = 0; i < (int) jump[j].size(); i++) {
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

template <class T> struct MinSparseTable {
    std::vector<T> v;
    std::vector<std::vector<int>> jump;

    int level(int x) { return 31 - __builtin_clz(x); }

    int comb(int a, int b) {
        return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
    }

    void init(const std::vector<T>& _v) {
        v = _v;
        jump = {std::vector<int>((int) v.size())};
        iota(jump[0].begin(), jump[0].end(), 0);
        for (int j = 1; (1 << j) <= (int) v.size(); j++) {
            jump.push_back(std::vector<int>((int) v.size() - (1 << j) + 1));
            for (int i = 0; i < (int) jump[j].size(); i++) {
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
        sum[ind] =  max(sum[2 * ind], sum[2 * ind + 1]);
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
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind + 1, M + 1, R));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vi a(n);
    f0r(i, n) cin >> a[i];
    f0r(i, n) a.pb(a[i]);

    MinSparseTable<int> Min; 
    MaxSparseTable<int> Max;
    Min.init(a);
    Max.init(a);
    LazySeg<int> Seg;
    LazySeg<int> Left;
    LazySeg<int> Right;
    LazySeg<int> All;
    Left.init(2 * n);
    Right.init(2 * n);
    All.init(2 * n);

    auto first_less = [&](int targ, int bnd) -> int {
        if (targ == bnd) return -1;
        int val = Min.query(targ, targ);
        if (targ < bnd) {
            int lo = targ + 1;
            int hi = bnd;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (Min.query(targ, mid) == val) lo = mid + 1;
                else hi = mid;
            }
            if (Min.query(targ, lo) != val) return lo;
            if (Min.query(targ, hi) != val) return hi;
        } else {
            int lo = bnd;
            int hi = targ - 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (Min.query(mid, targ) == val) hi = mid - 1;
                else lo = mid;
            }
            if (Min.query(hi, targ) != val) return hi;
            if (Min.query(lo, targ) != val) return lo;
        }
        return -1;
    };

    auto first_more = [&](int targ, int bnd) -> int {
        if (targ == bnd) return -1;
        int val = Max.query(targ, targ);
        if (targ < bnd) {
            int lo = targ + 1;
            int hi = bnd;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (Max.query(targ, mid) == val) lo = mid + 1;
                else hi = mid;
            }
            if (Max.query(targ, lo) != val) return lo;
            if (Max.query(targ, hi) != val) return hi;
        } else {
            int lo = bnd;
            int hi = targ - 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (Max.query(mid, targ) == val) hi = mid - 1;
                else lo = mid;
            }
            if (Max.query(hi, targ) != val) return hi;
            if (Max.query(lo, targ) != val) return lo;
        }
        return -1;
    };

    f0r(i, n) {
        int idx = first_less(i, 0);
        if (idx != -1) {
            Right.upd(idx+1, i-1, 1);
        } else {
            Right.upd(0, i-1, 1);
        }
        idx = first_less(i, n-1);
        if (idx != -1) {
            Left.upd(i+1, idx-1, 1);
        } else {
            Left.upd(i+1, n-1, 1);
        }
    }

    f0r(i, n) {
        All.upd(i, i, Left.qmax(i, i) + Right.qmax(i, i));
    }

    const int INF = 1e9;
    pi best = {INF, INF};

    f0r(i, n) {
        ckmin(best, {All.qmax(i, i+n-1), i});
        // cout << "ALL: ";
        // f1r(j, i, i+n) cout << All.qmax(j, j) << " ";
        // cout << endl;
        // cout << "ARRAY: ";
        // f1r(j, i, i+n) cout << Min.query(j, j) << " ";
        // cout << endl;
        { // removing i
            int idx = first_less(i, i+n-1);
            if (idx != -1) {
                Left.upd(i+1, idx-1, -1);
                All.upd(i+1, idx-1, -1);
            } else {
                Left.upd(i+1, i+n-1, -1);
                All.upd(i+1, i+n-1, -1);
            }
        }
        { // adding i+n
            int idx = first_less(i+n, i+1);
            if (idx != -1) {
                Right.upd(idx+1, i+n-1, 1);
                All.upd(idx+1, i+n-1, 1);
            } else {
                Right.upd(i+1, i+n-1, 1);
                All.upd(i+1, i+n-1, 1);
            }
        }
        {
            int idx = first_less(i+n, i+1);
            if (idx != -1) {
                Left.upd(i+n, i+n, Left.qmax(idx, idx)+1);
            } 
        }
        All.upd(i+n, i+n, Left.qmax(i+n, i+n) + Right.qmax(i+n, i+n));
    }

    cout << best.f+1 << " " << best.s << '\n';



    return 0;
}