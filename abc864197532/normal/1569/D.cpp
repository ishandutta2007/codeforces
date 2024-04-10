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
const int mod = 998244353, N = 100001, logN = 20, K = 80000;
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector <pii> on_x, on_y;
    for (int i = 0, x, y; i < k; ++i) {
        cin >> x >> y;
        int id_x = -1, id_y = -1;
        auto it = lower_bound(all(a), x);
        if (it != a.end() && *it == x) id_x = it - a.begin();
        auto it2 = lower_bound(all(b), y);
        if (it2 != b.end() && *it2 == y) id_y = it2 - b.begin();
        if (id_x == -1) {
            on_y.eb(x, id_y);
        } else if (id_y == -1) {
            on_x.eb(y, id_x);
        }
    }
    sort(all(on_x)), sort(all(on_y));
    lli ans = 0;
    vector <int> cnt(n, 0);
    for (int i = 0, j = 0, now = 0; i < on_x.size(); i = j, now++) {
        while (j < on_x.size() && on_x[j].X < b[now]) j++;
        for (int k = i; k < j; ++k) {
            ans -= cnt[on_x[k].Y];
            cnt[on_x[k].Y]++;
        }
        ans += 1ll * (j - i) * (j - i - 1) / 2;
        for (int k = i; k < j; ++k) {
            cnt[on_x[k].Y]--;
        }
    }
    cnt.assign(m, 0);
    for (int i = 0, j = 0, now = 0; i < on_y.size(); i = j, now++) {
        while (j < on_y.size() && on_y[j].X < a[now]) j++;
        for (int k = i; k < j; ++k) {
            ans -= cnt[on_y[k].Y];
            cnt[on_y[k].Y]++;
        }
        ans += 1ll * (j - i) * (j - i - 1) / 2;
        for (int k = i; k < j; ++k) {
            cnt[on_y[k].Y]--;
        }
    }
    cout << ans << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}