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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 111;

struct Seg {
    int l, r, m;
    long long val, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
        val = lz = 0;
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
};

int main () {
    owo;
    int n, p;
    cin >> n >> p;
    vector <int> a(n);
    vector <int> pos[1000001];
    Seg root(0, n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == p) root.add(i, n, -1);
        else pos[a[i]].pb(i);
    }
    for (int ans = 1; ans <= 1000000; ++ans) if (ans != p) {
        for (int p : pos[ans]) root.add(p, n, 1);
        if (root.val >= 0) {
            cout << ans << endl;
            return 0;
        }
        for (int p : pos[ans]) root.add(p, n, -1);
    }
    cout << -1 << endl;
}