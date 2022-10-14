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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 20, K = 111;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        vv <bool> is(n, m, false);
        for (int h = k; h <= 20; ++h) {
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '*') {
                int cnt = 1;
                for (int x = 1; x <= h; ++x) {
                    if (0 <= i - x && i - x < n && 0 <= j - x && j - x <= m && s[i - x][j - x] == '*') {
                        cnt++;
                    }
                    if (0 <= i - x && i - x < n && 0 <= j + x && j + x <= m && s[i - x][j + x] == '*') {
                        cnt++;
                    }
                }
                if (cnt == h * 2 + 1) {
                    is[i][j] = true;
                    for (int x = 1; x <= h; ++x) {
                        if (0 <= i - x && i - x < n && 0 <= j - x && j - x <= m && s[i - x][j - x] == '*') {
                            is[i - x][j - x] = true;
                        }
                        if (0 <= i - x && i - x < n && 0 <= j + x && j + x <= m && s[i - x][j + x] == '*') {
                            is[i - x][j + x] = true;
                        }
                    }
                }
            }
        }
        bool ans = true;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '*') {
            ans &= is[i][j];
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}