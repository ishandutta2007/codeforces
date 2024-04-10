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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1002, logN = 19, K = 111, M = 1000006, INF = 1e9 + 87;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector <int> ans(n * m);
        {
            // col
            int cnt = 0;
            vector <bool> is(m, false);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!is[j] && s[i * m + j] == '1')
                        cnt++, is[j] = true;
                    ans[i * m + j] += cnt;
                }
            }
        }
        {
            // row
            vector <bool> ok(n * m, false);
            int cnt = 0;
            for (int i = 0; i < n * m; ++i) {
                if (i - m >= 0)
                    cnt -= s[i - m] == '1';
                cnt += s[i] == '1';
                ok[i] = cnt > 0;
            }
            vector <int> pre(m, 0);
            for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
                pre[j] += ok[i * m + j];
                ans[i * m + j] += pre[j];
            }
        }
        for (int i = 0; i < n * m; ++i)
            cout << ans[i] << " \n"[i == n * m - 1];
    }
}