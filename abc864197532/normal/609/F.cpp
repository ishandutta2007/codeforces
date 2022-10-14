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
const int mod = 1e9 + 7, N = 2520, logN = 20;

struct Seg {
    int l, r, m;
    lli mx;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), mx(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void set(int p, lli v) {
        if (r - l == 1) mx = v;
        else mx = max(mx, v), ch[p >= m]->set(p, v);
    }
    int query(int a, int b, int v) {
        if (a <= l && r <= b) {
            if (mx < v) return 1 << 30;
            if (r - l == 1) return l;
            if (ch[0]->mx >= v) return ch[0]->query(a, b, v);
            return ch[1]->query(a, b, v);
        }
        int mn = 1 << 30;
        if (a < m) mn = min(mn, ch[0]->query(a, b, v));
        if (m < b) mn = min(mn, ch[1]->query(a, b, v));
        return mn;
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <pair <long long, long long>> frog(n), mos(q);
    vector <int> v, idx(n), to(n);
    for (int i = 0; i < n; ++i) cin >> frog[i], v.pb(frog[i].X);
    for (int i = 0; i < q; ++i) cin >> mos[i];
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    Seg root(0, n);
    for (int i = 0; i < n; ++i) {
        idx[i] = lower_bound(all(v), frog[i].X) - v.begin();
        root.set(idx[i], frog[i].X + frog[i].Y);
        to[idx[i]] = i;
    }
    multiset <pii> remain;
    vector <int> ans(n, 0);
    auto eat = [&](int id, int len) {
        ans[id]++;
        frog[id].Y += len;
        root.set(idx[id], frog[id].X + frog[id].Y);
    };
    for (int i = 0; i < q; ++i) {
        int mn = root.query(0, upper_bound(all(v), mos[i].X) - v.begin(), mos[i].X);
        if (mn == 1 << 30) remain.insert(mos[i]);
        else {
            int id = to[mn];
            eat(id, mos[i].Y);
            vector <pii> eaten;
            for (auto it = remain.lower_bound({frog[id].X, -1}); it != remain.end() && it->X <= frog[id].X + frog[id].Y; ++it) {
                eat(id, it->Y);
                eaten.pb(*it);
            }
            for (pii A : eaten) remain.erase(remain.lower_bound(A));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ' << frog[i].Y << endl;
    }
}