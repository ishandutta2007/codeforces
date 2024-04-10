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
const int mod = 1e9 + 7, N = 400001, logN = 18, K = 1000;

struct Seg {
    int l, r, m;
    pii mn, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mn(mp(1 << 30, -1)), lz(mp(1 << 30, -1)) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {mn = min(ch[0]->mn, ch[1]->mn);}
    void give(pii v) {mn = min(mn, v), lz = min(lz, v);}
    void push() {
        ch[0]->give(lz), ch[1]->give(lz);
        lz = mp(1 << 30, -1);
    }
    void modify(int a, int b, pii v) {
        if (a <= l && r <= b) give(v);
        else {
            push();
            if (a < m) ch[0]->modify(a, b, v);
            if (m < b) ch[1]->modify(a, b, v);
            pull();
        }
    }
    pii query(int a, int b) {
        if (a <= l && r <= b) return mn;
        push();
        pii ans = mp(1 << 30, -1);
        if (a < m) ans = min(ans, ch[0]->query(a, b));
        if (m < b) ans = min(ans, ch[1]->query(a, b));
        return ans;
    }
};

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <vector <pii>> a(n);
    vector <int> v;
    for (int i = 0, row, l, r; i < m; ++i) {
        cin >> row >> l >> r, --l, --row;
        a[row].eb(l, r), v.pb(l), v.pb(r);
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for (int i = 0; i < n; ++i) for (pii &A : a[i]) {
        A.X = lower_bound(all(v), A.X) - v.begin();
        A.Y = lower_bound(all(v), A.Y) - v.begin();
    }
    Seg root(0, v.size());
    vector <int> dp(n, 1 << 30), pt(n + 1, -1);
    dp[0] = 0;
    pt[0] = -1;
    for (pii A : a[0]) {
        root.modify(A.X, A.Y, mp(0, 0));
    }
    for (int i = 1; i < n; ++i) {
        dp[i] = i;
        pt[i] = -1;
        pii mn = mp(1 << 30, -1);
        for (pii A : a[i]) {
            mn = min(mn, root.query(A.X, A.Y));
        }
        if (mn.Y != -1 && dp[i] > mn.X + i - 1) {
            dp[i] = mn.X + i - 1;
            pt[i] = mn.Y;
        }
        for (pii A : a[i]) {
            root.modify(A.X, A.Y, mp(dp[i] - i, i));
        }
    }
    int best = -1;
    for (int i = 0; i < n; ++i) {
        if (best == -1 || dp[best] + n - best - 1 > dp[i] + n - i - 1) {
            best = i;
        }
    }
    vector <int> ans;
    for (int i = best + 1; i < n; ++i) ans.pb(i);
    while (best != -1) {
        int nxt = pt[best];
        for (int i = nxt + 1; i < best; ++i) ans.pb(i);
        best = nxt;
    }
    cout << ans.size() << endl;
    for (int &i : ans) i++;
    printv(all(ans));
}