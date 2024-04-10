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
const int mod = 1e9 + 7, N = 8001, logC = 30, logN = 19, K = 111, M = 4e6;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <bool> is(n, false);
    vector <pii> v;
    for (int i = 0, t, l, r; i < m; ++i) {
        cin >> t >> l >> r, --l;
        if (t == 1) {
            for (int i = l; i + 1 < r; ++i) is[i] = true;
        } else {
            v.eb(l, r);
        }
    }
    vector <pii> a;
    vector <int> ans(n, -1);
    int st = -1;
    for (int i = 0; i < n; ++i) {
        if (is[i]) {
            if (st == -1) st = i;
        } else {
            if (st != -1) a.eb(st, i), st = -1;
        }
    }
    for (pii A : a) {
        int now = -1999;
        for (int i = A.X; i <= A.Y; ++i) {
            ans[i] = now += 2000;
        }
    }
    reverse(all(ans));
    int now = 0;
    for (int &i : ans) if (i == -1) i = now += 2;
    reverse(all(ans));
    for (pii A : v) {
        if (is_sorted(ans.begin() + A.X, ans.begin() + A.Y)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    printv(all(ans));
}