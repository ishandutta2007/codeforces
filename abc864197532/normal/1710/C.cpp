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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200005;

int dp[N][8][8][2]; // idx, largest mask, have < mask (1 -> yes), ans ok

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

void solve() {
    string S; cin >> S;
    int n = S.length();
    int pt = n - 1;
    while (~pt && S[pt] == '1')
        S[pt] = '0', pt--;
    if (pt == -1)
        S.insert(S.begin(), '1'), n++;
    else
        S[pt]++;
    dp[0][7][0][0] = 1; 
    for (int i = 0; i < n; ++i) for (int j = 0; j < 8; ++j) for (int s = 0; s < 8; ++s) for (int ok = 0; ok < 2; ++ok) if (dp[i][j][s][ok]) {
        for (int t = 0; t < 8; ++t) {
            int nxts = 0;
            if (s & 1 || (S[i] == '1' && ~t & 1))
                nxts |= 1;
            if (s & 2 || (S[i] == '1' && ~t & 2))
                nxts |= 2;
            if (s & 4 || (S[i] == '1' && ~t & 4))
                nxts |= 4;
            if (~s & 1 && (S[i] == '0' && t & 1))
                continue;
            if (~s & 2 && (S[i] == '0' && t & 2))
                continue;
            if (~s & 4 && (S[i] == '0' && t & 4))
                continue;
            int a[3] = {0, 0, 0};
            if (t & 1)
                a[0] ^= 1, a[1] ^= 1;
            if (t & 2)
                a[0] ^= 1, a[2] ^= 1;
            if (t & 4)
                a[1] ^= 1, a[2] ^= 1;
            int nxtok = ok;
            if (j == 1 && !a[0] && a[1] && a[2])
                nxtok = 1;
            if (j == 2 && !a[1] && a[0] && a[2])
                nxtok = 1;
            if (j == 4 && !a[2] && a[0] && a[1])
                nxtok = 1;
            if (j & 1)
                a[0] |= 2;
            if (j & 2)
                a[1] |= 2;
            if (j & 4)
                a[2] |= 2;
            int mx = max({a[0], a[1], a[2]});
            int nxtj = 0;
            for (int i = 0; i < 3; ++i) if (mx == a[i])
                nxtj |= 1 << i;
            add(dp[i + 1][nxtj][nxts][nxtok], dp[i][j][s][ok]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; ++i)
        add(ans, dp[n][i][7][1]);
    cout << ans << '\n';
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}