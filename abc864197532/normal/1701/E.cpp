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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 100005, logN = 20, M = 6e6;

int lcp[5001][5001];

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string s, t;
        cin >> n >> m >> s >> t;
        vector <int> pre(m + 1), suf(m + 1);
        for (int i = 1; i <= m; ++i) {
            pre[i] = pre[i - 1] + 1;
            while (pre[i] <= n && s[pre[i] - 1] != t[i - 1])
                pre[i]++;
        }
        if (pre[m] > n) {
            cout << -1 << endl;
            continue;
        }
        for (int i = m - 1; ~i; --i) {
            suf[i] = suf[i + 1] + 1;
            while (suf[i] <= n && s[n - suf[i]] != t[i])
                suf[i]++;
        }
        for (int i = n - 1; ~i; --i) for (int j = m - 1; ~j; --j) {
            if (s[i] == t[j])
                lcp[i][j] = (i + 1 < n && j + 1 < m ? lcp[i + 1][j + 1] : 0) + 1;
            else
                lcp[i][j] = 0;
        }
        // s = A + B + C, t = D + B + E
        // D = sub of A, E = sub of C, min 2|A| + [|A| > 0] + C
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (pre[j] <= i && i <= n - suf[j]) {
                // start from (i, j) is ok
                int A = i, B = lcp[i][j], C = n - A - B;
                // test(A, B, C);
                ans = min(ans, A + A - j + C + (A > 0));
            }
        }
        cout << ans << endl;
    }
}