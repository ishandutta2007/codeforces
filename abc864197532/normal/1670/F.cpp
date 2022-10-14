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

int C[N][N];

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

int solve(int n, lli bound, lli x) {
    vv <int> dp(n + 5, 3, 0); // 0 < bound, 1 = bound, 2 > bound
    dp[0][1] = 1;
    for (int bit = 0; bit < 60; ++bit) {
        vv <int> nxt(n + 5, 3, 0);
        for (int now = x >> bit & 1; now <= n; now += 2) for (int s = 0; s < n + 5; ++s) {
            int ns = s + now >> 1, lst = (s + now) & 1;
            for (int t : {0, 1, 2}) if (dp[s][t]) {
                int ad = 1ll * dp[s][t] * C[n][now] % mod;
                int a = 0, b = 0;
                if (t == 0)
                    b = 1;
                if (t == 2)
                    a = 1;
                if (bound >> bit & 1)
                    b |= 2;
                if (lst)
                    a |= 2;
                if (a < b)
                    add(nxt[ns][0], ad);
                else if (a == b)
                    add(nxt[ns][1], ad);
                else
                    add(nxt[ns][2], ad);
            }
        }
        dp = nxt;
    }
    int ans = 0;
    add(ans, dp[0][0]), add(ans, dp[0][1]);
    return ans;
}

int main () {
    owo;
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            add(C[i][j], C[i - 1][j - 1]);
            add(C[i][j], C[i - 1][j]);
        }
    }
    int n;
    lli l, r, x;
    cin >> n >> l >> r >> x, --l;
    cout << (solve(n, r, x) + mod - solve(n, l, x)) % mod << '\n';
}