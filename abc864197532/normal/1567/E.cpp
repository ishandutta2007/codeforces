/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 401, logN = 20, K = 80000;

lli get(int x) {
    return 1ll * (x + 1) * (x + 2) / 2;
}



struct val {
    int lsum, rsum, len;
    lli oth;
    val (int x) {
        if (x) lsum = rsum = 1;
        else lsum = rsum = 0;
        len = 1, oth = 0;
    }
    val operator + (const val &o) {
        val out = val(0);
        bool is = true;
        if (lsum == len) {
            out.lsum = lsum + o.lsum;
            is = false;
        } else {
            out.lsum = lsum;
        }
        if (o.rsum == o.len) {
            out.rsum = rsum + o.rsum;
            is = false;
        } else {
            out.rsum = o.rsum;
        }
        out.oth = oth + o.oth;
        if (is) out.oth += get(rsum + o.lsum);
        out.len = len + o.len;
        return out;
    }
};

struct Seg {
    int l, r, m;
    val cur;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), cur(val(0)) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        cur = ch[0]->cur + ch[1]->cur;
    }
    void chg(int x, int v) {
        if (r - l == 1) cur = val(v);
        else ch[x >= m]->chg(x, v), pull();
    }
    val query(int a, int b) {
        if (a <= l && r <= b) return cur;
        val cur = val(0); cur.len = 0;
        if (a < m) cur = cur + ch[0]->query(a, b);
        if (m < b) cur = cur + ch[1]->query(a, b);
        return cur;
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Seg root(0, n);
    for (int i = 0; i + 1 < n; ++i) {
        root.chg(i, a[i] <= a[i + 1]);
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r, --l;
        if (t == 1) {
            a[l] = r;
            if (l) root.chg(l - 1, a[l - 1] <= a[l]);
            if (l + 1 < n) root.chg(l, a[l] <= a[l + 1]);
        } else {
            if (l + 1 == r) {
                cout << 1 << endl;
                continue;
            }
            val res = root.query(l, r - 1);
            lli ans = res.oth + get(res.lsum) + get(res.rsum);
            if (res.lsum == res.len) ans -= get(res.lsum);
            cout << ans << endl;
        }
    }
}