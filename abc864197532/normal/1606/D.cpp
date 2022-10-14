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
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 60, logN = 18, K = 1 << 9, G = 3;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vv <int> a(n, m, 0);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
            cin >> a[i][j];
        vector <int> p(n);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) {
            return a[i][0] < a[j][0];
        });
        vv <int> pre_mx(n, m + 1, 0), pre_mn(n, m + 1, 1 << 30), suf_mx(n, m + 1, 0), suf_mn(n, m + 1, 1 << 30);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pre_mx[i][j] = max(pre_mx[i][j - 1], a[p[i]][j - 1]);
                pre_mn[i][j] = min(pre_mn[i][j - 1], a[p[i]][j - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; ~j; --j) {
                suf_mx[i][j] = max(suf_mx[i][j + 1], a[p[i]][j]);
                suf_mn[i][j] = min(suf_mn[i][j + 1], a[p[i]][j]);
            }
        }
        int ansx = -1, ansy;
        for (int j = 1; j < m; ++j) {
            vector <int> pmx(n + 1, 0), pmn(n + 1, 1 << 30), smx(n + 1, 0), smn(n + 1, 1 << 30);
            for (int i = 0; i < n; ++i) {
                pmx[i + 1] = max(pmx[i], pre_mx[i][j]);
                pmn[i + 1] = min(pmn[i], suf_mn[i][j]);
            }
            for (int i = n - 1; ~i; --i) {
                smn[i] = min(smn[i + 1], pre_mn[i][j]);
                smx[i] = max(smx[i + 1], suf_mx[i][j]);
            }
            for (int i = 1; i < n; ++i) {
                if (pmx[i] < smn[i] && pmn[i] > smx[i]) {
                    ansx = i, ansy = j;
                    break;
                }
            }
            if (~ansx)
                break;
        }
        if (~ansx) {
            cout << "YES\n";
            string ans(n, ' ');
            for (int i = 0; i < n; ++i) {
                if (i < ansx)
                    ans[p[i]] = 'B';
                else
                    ans[p[i]] = 'R';
            }
            cout << ans << ' ' << ansy << endl;
        } else {
            cout << "NO\n";
        }
    }
}