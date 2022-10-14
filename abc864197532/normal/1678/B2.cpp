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
const int mod = 998244353, N = 1000002, logN = 19, K = 111, M = 1000006, INF = 1e9 + 87;

pii add(pii i, pii j) {
    return mp(i.X + j.X, i.Y + j.Y);
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vv <pii> dp(n + 1, 2, mp(1 << 30, 0));
        dp[0][0] = mp(0, 1), dp[0][1] = mp(0, 1);
        for (int i = 0; i < n; i += 2) {
            // to (0, 0)
            int ad = (s[i] == '1') + (s[i + 1] == '1');
            dp[i + 2][0] = min(dp[i + 2][0], add(dp[i][0], mp(ad, 0)));
            dp[i + 2][0] = min(dp[i + 2][0], add(dp[i][1], mp(ad, 1)));
            // to (1, 1)
            ad = (s[i] == '0') + (s[i + 1] == '0');
            dp[i + 2][1] = min(dp[i + 2][1], add(dp[i][0], mp(ad, 1)));
            dp[i + 2][1] = min(dp[i + 2][1], add(dp[i][1], mp(ad, 0)));
        }
        pii ans = min(dp[n][0], dp[n][1]);
        cout << ans.X << ' ' << ans.Y << '\n';
    }
}