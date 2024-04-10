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
const int mod = 998244353, N = 1000002, M = 150000, logN = 20, K = 1000;

void solve() {
    int n;
    cin >> n;
    vv <int> r(n, 5, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < 5; ++j) cin >> r[i][j];
    auto chk = [&](int i, int j) {
        // i beat j?
        int cnt = 0;
        for (int k = 0; k < 5; ++k) cnt += r[i][k] < r[j][k];
        return cnt >= 3;
    };
    vector <int> remain(n, 0);
    iota(all(remain), 0);
    while (remain.size() > 1) {
        vector <int> A;
        for (int i = 0; i < remain.size(); i += 2) {
            if (i + 1 == remain.size()) A.pb(remain[i]);
            else if (chk(remain[i], remain[i + 1])) A.pb(remain[i]);
            else A.pb(remain[i + 1]);
        }
        remain = A;
    }
    for (int i = 0; i < n; ++i) if (i != remain[0]) {
        if (chk(i, remain[0])) {
            cout << -1 << endl;
            return;
        }
    }
    cout << remain[0] + 1 << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}