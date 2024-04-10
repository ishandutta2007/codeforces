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
    int n, k;
    cin >> n >> k;
    vector <pii> a(k);
    vector <bool> vis(n * 2, false);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        vis[--a[i].X] = vis[--a[i].Y] = true;
    }
    int ans = 0, remain = 2 * (n - k);
    for (int i = 0; i < k; ++i) {
        if (a[i].X > a[i].Y) swap(a[i].X, a[i].Y);
        int cnt = 0;
        for (int j = a[i].X + 1; j < a[i].Y; ++j) if (!vis[j]) {
            cnt++;
        }
        ans += min(cnt, remain - cnt);
    }
    for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j) {
        int cnt = 0;
        for (int ii = a[i].X + 1; ii < a[i].Y; ++ii) if (ii == a[j].X || ii == a[j].Y) {
            cnt ^= 1;
        }
        ans += cnt;
    }
    cout << ans + (n - k) * (n - k - 1) / 2 << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}