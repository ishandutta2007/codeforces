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
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 300001, logC = 30, logN = 19, K = 550, M = 4e6;

vector <pii> chg;
map <pii, int> m1;

struct Seg {
    int l, r, m, ans;
    Seg* ch[2];
    char c;
    Seg (int _l, int _r, string &s, int d = 0, int pos = 0) : l(_l), r(_r), m(l + r >> 1), ans(0) {
        if (r - l > 1) {
            c = s[m1[{d, pos}]];
            ch[0] = new Seg(l, m, s, d + 1, pos * 2);
            ch[1] = new Seg(m, r, s, d + 1, pos * 2 + 1);
            pull();
        } else {
            ans = 1;
        }
    }
    void pull() {
        if (c == '?') ans = ch[0]->ans + ch[1]->ans;
        if (c == '0') ans = ch[0]->ans;
        if (c == '1') ans = ch[1]->ans;
    }
    void modify(int d, int pos, char _c) {
        if (d == 0) c = _c;
        else if (pos >> (d - 1) & 1) {
            ch[1]->modify(d - 1, pos, _c);
        } else {
            ch[0]->modify(d - 1, pos, _c);
        }
        pull();
    }
};

int main () {
    owo;
    int n, q;
    string s;
    cin >> n >> s;
    int now = n - 1, cur = 0;
    for (int i = 0; i < (1 << n) - 1; ++i) {
        chg.eb(now, cur);
        m1[{now, cur}] = i;
        cur++;
        if (cur == 1 << now) now--, cur = 0;
    }
    cin >> q;
    Seg root(0, 1 << n, s);
    while (q--) {
        int p;
        char c;
        cin >> p >> c, --p;
        pii A = chg[p];
        root.modify(A.X, A.Y, c);
        cout << root.ans << '\n';
    }
}