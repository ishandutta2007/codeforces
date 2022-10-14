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
const int mod = 998244353, N = 3001, logN = 20, K = 111, C = 7;

int dp[N][N];
vector <int> pos[N];
int c[N];

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            pos[i].clear();
        for (int i = 0; i < n; ++i)
            cin >> c[i], pos[--c[i]].pb(i);
        for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j)
            dp[i][j] = 0;
        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len, add = c[l] == c[r - 1];
                dp[l][r] = add;
                for (int x : pos[c[l]]) if (l < x + 1 && x + 1 < r) {
                    dp[l][r] = max(dp[l][r], dp[l][x + 1] + dp[x + 1][r] + add);
                }
                for (int x : pos[c[r - 1]]) if (l < x && x < r) {
                    dp[l][r] = max(dp[l][r], dp[l][x] + dp[x][r] + add);
                }
            }
        }
        cout << n - dp[0][n] - 1 << '\n';
    }
}