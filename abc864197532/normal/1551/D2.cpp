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
const int mod = 1e9 + 7, N = 300005, logN = 20, K = 1000;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int all = n * m / 2;
        if (n & 1) {
            if (m / 2 <= k && k <= all && k % 2 == (m / 2) % 2) {
                cout << "YES\n";
                k = all - k;
                vector <string> s(n, "");
                string a[4] = {"aacc", "bbdd", "ccaa", "ddbb"};
                for (int i = 0; i < n; ++i) {
                    while (s[i].length() < m) s[i] += a[i % 4];
                    while (s[i].length() > m) s[i].pop_back();
                }
                for (int i = 0; i < n; i += 2) for (int j = 0; j < m; j += 2) {
                    if (!k) break;
                    k -= 2;
                    swap(s[i][j + 1], s[i + 1][j]);
                }
                for (string &t : s) cout << t << '\n';
            } else {
                cout << "NO\n";
            }
        } else if (m & 1) {
            if (k % 2 == 0 && 0 <= k && k <= all - n / 2) {
                cout << "YES\n";
                vector <string> s(n, "");
                string a = "abcd", b = "cdab";
                for (int i = 0; i < n; ++i) {
                    if (i % 4 <= 1) {
                        while (s[i].length() < m) s[i] += a;
                    } else {
                        while (s[i].length() < m) s[i] += b;
                    }
                    while (s[i].length() > m) s[i].pop_back();
                }
                for (int i = 0; i < n; i += 2) for (int j = 0; j + 1 < m; j += 2) {
                    if (!k) break;
                    k -= 2;
                    swap(s[i][j + 1], s[i + 1][j]);
                }
                for (string &t : s) cout << t << '\n';
            } else {
                cout << "NO\n";
            }
        } else {
            if (k % 2 == 0) {
                cout << "YES\n";
                vector <string> s(n, "");
                string a = "abcd", b = "cdab";
                for (int i = 0; i < n; ++i) {
                    if (i % 4 <= 1) {
                        while (s[i].length() < m) s[i] += a;
                    } else {
                        while (s[i].length() < m) s[i] += b;
                    }
                    while (s[i].length() > m) s[i].pop_back();
                }
                for (int i = 0; i < n; i += 2) for (int j = 0; j < m; j += 2) {
                    if (!k) break;
                    k -= 2;
                    swap(s[i][j + 1], s[i + 1][j]);
                }
                for (string &t : s) cout << t << '\n';
            } else cout << "NO\n";
        }
    }
}