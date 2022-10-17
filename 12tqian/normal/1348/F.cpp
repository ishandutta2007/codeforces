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

struct I { 
    int i, l, r;
    I(int i, int l, int r) : i(i), l(l), r(r) {}
};

const int INF = 1e9;

template <class T> struct MinSegmentTree {
    const T ID = {INF, INF};

    T comb(T a, T b) {
        return min(a, b);
    }

    int n;
    std::vector<T> seg;

    void init(int _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(int p) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }

    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    void add(int p, T val) {
        seg[p += n] += val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        if (l > r) return ID;
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

template <class T> struct MaxSegmentTree {
    const T ID = {-INF, -INF};

    T comb(T a, T b) {
        return min(a, b);
    }

    int n;
    std::vector<T> seg;

    void init(int _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }

    void pull(int p) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }

    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    void add(int p, T val) {
        seg[p += n] += val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        if (l > r) return ID;
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<I> ivals;
    f0r(i, n) {
        int a, b; cin >> a >> b;
        a--, b--;
        ivals.pb(I(i, a, b));
    }

    vector<vector<I>> beg(n);

    f0r(i, n) {
        beg[ivals[i].l].pb(ivals[i]);
    }

    set<pi> match; // ready to be matched

    vi m1(n);

    f0r(i, n) {
        each(e, beg[i]) {
            match.emplace(e.r, e.i);
        }
        auto x = *match.begin();
        match.erase(match.begin());
        m1[x.s] = i;
    }

    vi m2(n); // second matching

    auto double_finish = [&]() {
        cout << "NO\n";
        each(e, m1) cout << e+1 << " ";
        cout << '\n';
        each(e, m2) cout << e+1 << " ";
        cout << '\n';
        exit(0);
    };
    m2 = m1;

    auto contains = [&](int l, int r, int i) -> int {
        return l <= i && i <= r;
    };

    vi segs(n);

    MaxSegmentTree<pi> Left;
    MinSegmentTree<pi> Right;

    Left.init(n); Right.init(n);

    f0r(i, n) {
        segs[m1[i]] = i;
    }

    f0r(i, n) {
        int id = segs[i];
        Right.upd(i, {ivals[id].l, i}); 
        Left.upd(i, {ivals[id].r, i});
    }

    f0r(i, n) {
        int id = segs[i];
        int l = ivals[id].l;
        int r = ivals[id].r;
        auto qq = Right.query(i+1, r);
        if (qq.f <= i) {
            int j = qq.s;
            swap(m2[segs[i]], m2[segs[j]]);
            double_finish();
        }
        qq = Left.query(l, i-1);
        if (qq.f >= i) {
            int j = qq.s;
            swap(m2[segs[i]], m2[segs[j]]);
            double_finish();
        }
    }

    cout << "YES" << '\n';
    each(e, m1) cout << e+1 << " ";
    cout << '\n';



    return 0;
}