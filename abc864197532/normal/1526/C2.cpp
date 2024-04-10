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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
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
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200001, logC = 30, logN = 19, K = 111, M = 4e6;

struct Seg {
    int l, r, m;
    long long val, lz;
    Seg* ch[2];
    Seg (int _l, int _r, vector <lli> &a) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            val = a[l];
        }
        lz = 0;
    }
    void pull() {val = min(ch[0]->val, ch[1]->val);}
    void push() {
        if (r - l > 1 && lz) {
            ch[0]->lz += lz;
            ch[0]->val += lz;
            ch[1]->lz += lz;
            ch[1]->val += lz;
        }
        lz = 0;
    }
    void add(int a, int b, long long v) {
        if (a <= l && r <= b) val += v, lz += v;
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    long long query(int a, int b) {
        if (a <= l && r <= b) return val;
        push();
        long long ans = 1ll << 60;
        if (a < m) ans = min(ans, ch[0]->query(a, b));
        if (m < b) ans = min(ans, ch[1]->query(a, b));
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector <int> a(n);
    vector <lli> pre(n, 0);
    vector <int> p;
    for (int i = 0; i < n; ++i) {
        if (i) pre[i] = pre[i - 1];
        cin >> a[i];
        if (a[i] >= 0) pre[i] += a[i], ans++;
        else p.pb(i);
    }
    Seg root(0, n, pre);
    sort(all(p), [&](int i, int j) {
        return a[i] > a[j];
    });
    for (int i : p) {
        root.add(i, n, a[i]);
        if (root.query(i, n) >= 0) ans++;
        else {
            root.add(i, n, -a[i]);
        }
    }
    cout << ans << endl;
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}