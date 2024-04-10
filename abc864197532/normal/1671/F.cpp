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
const int mod = 998244353, N = 505, logN = 20, K = 111, M = 4e7;

int cnt[13][12][12], dp[12][12][12][12], inv[12];

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

lli C(int n, int m) {
    if (n < 0 || m < 0 || n < m)
        return 0;
    lli ans = 1;
    for (int i = n; i > n - m; --i)
        ans = ans * i % mod;
    for (int i = 1; i <= m; ++i)
        ans = ans * inv[i] % mod;
    return ans;
}

int main () {
    owo;
    inv[1] = 1;
    for (int i = 2; i < 12; ++i)
        inv[i] = mod - 1ll * (mod / i) * inv[mod % i] % mod;
    cnt[2][1][1] = 1;
    cnt[3][2][1] = 2;
    cnt[3][3][2] = 1;
    cnt[4][3][1] = 3;
    cnt[4][3][2] = 1;
    cnt[4][4][1] = 1;
    cnt[4][4][2] = 4;
    cnt[4][5][2] = 3;
    cnt[4][6][3] = 1;
    cnt[5][4][1] = 4;
    cnt[5][4][2] = 4;
    cnt[5][5][1] = 2;
    cnt[5][5][2] = 12;
    cnt[5][5][3] = 2;
    cnt[5][6][1] = 2;
    cnt[5][6][2] = 12;
    cnt[5][6][3] = 4;
    cnt[5][7][2] = 9;
    cnt[5][7][3] = 6;
    cnt[5][8][2] = 3;
    cnt[5][8][3] = 6;
    cnt[5][9][3] = 4;
    cnt[5][10][4] = 1;
    cnt[6][5][1] = 5;
    cnt[6][5][2] = 10;
    cnt[6][5][3] = 1;
    cnt[6][6][1] = 3;
    cnt[6][6][2] = 28;
    cnt[6][6][3] = 13;
    cnt[6][7][1] = 4;
    cnt[6][7][2] = 35;
    cnt[6][7][3] = 29;
    cnt[6][7][4] = 1;
    cnt[6][8][1] = 3;
    cnt[6][8][2] = 35;
    cnt[6][8][3] = 41;
    cnt[6][8][4] = 4;
    cnt[6][9][1] = 1;
    cnt[6][9][2] = 30;
    cnt[6][9][3] = 44;
    cnt[6][9][4] = 7;
    cnt[6][10][2] = 17;
    cnt[6][10][3] = 45;
    cnt[6][10][4] = 7;
    cnt[6][11][2] = 8;
    cnt[6][11][3] = 30;
    cnt[6][11][4] = 11;
    cnt[7][6][1] = 6;
    cnt[7][6][2] = 20;
    cnt[7][6][3] = 6;
    cnt[7][7][1] = 4;
    cnt[7][7][2] = 55;
    cnt[7][7][3] = 50;
    cnt[7][7][4] = 3;
    cnt[7][8][1] = 6;
    cnt[7][8][2] = 80;
    cnt[7][8][3] = 118;
    cnt[7][8][4] = 18;
    cnt[7][9][1] = 6;
    cnt[7][9][2] = 95;
    cnt[7][9][3] = 186;
    cnt[7][9][4] = 48;
    cnt[7][10][1] = 6;
    cnt[7][10][2] = 101;
    cnt[7][10][3] = 230;
    cnt[7][10][4] = 85;
    cnt[7][10][5] = 2;
    cnt[7][11][1] = 2;
    cnt[7][11][2] = 94;
    cnt[7][11][3] = 260;
    cnt[7][11][4] = 113;
    cnt[7][11][5] = 4;
    cnt[8][7][1] = 7;
    cnt[8][7][2] = 35;
    cnt[8][7][3] = 21;
    cnt[8][7][4] = 1;
    cnt[8][8][1] = 5;
    cnt[8][8][2] = 96;
    cnt[8][8][3] = 145;
    cnt[8][8][4] = 26;
    cnt[8][9][1] = 8;
    cnt[8][9][2] = 155;
    cnt[8][9][3] = 358;
    cnt[8][9][4] = 124;
    cnt[8][9][5] = 3;
    cnt[8][10][1] = 9;
    cnt[8][10][2] = 207;
    cnt[8][10][3] = 616;
    cnt[8][10][4] = 313;
    cnt[8][10][5] = 16;
    cnt[8][11][1] = 11;
    cnt[8][11][2] = 250;
    cnt[8][11][3] = 859;
    cnt[8][11][4] = 567;
    cnt[8][11][5] = 53;
    cnt[9][8][1] = 8;
    cnt[9][8][2] = 56;
    cnt[9][8][3] = 56;
    cnt[9][8][4] = 8;
    cnt[9][9][1] = 6;
    cnt[9][9][2] = 154;
    cnt[9][9][3] = 350;
    cnt[9][9][4] = 126;
    cnt[9][9][5] = 4;
    cnt[9][10][1] = 10;
    cnt[9][10][2] = 268;
    cnt[9][10][3] = 898;
    cnt[9][10][4] = 552;
    cnt[9][10][5] = 48;
    cnt[9][11][1] = 12;
    cnt[9][11][2] = 389;
    cnt[9][11][3] = 1654;
    cnt[9][11][4] = 1404;
    cnt[9][11][5] = 204;
    cnt[9][11][6] = 1;
    cnt[10][9][1] = 9;
    cnt[10][9][2] = 84;
    cnt[10][9][3] = 126;
    cnt[10][9][4] = 36;
    cnt[10][9][5] = 1;
    cnt[10][10][1] = 7;
    cnt[10][10][2] = 232;
    cnt[10][10][3] = 742;
    cnt[10][10][4] = 448;
    cnt[10][10][5] = 43;
    cnt[10][11][1] = 12;
    cnt[10][11][2] = 427;
    cnt[10][11][3] = 1967;
    cnt[10][11][4] = 1887;
    cnt[10][11][5] = 357;
    cnt[10][11][6] = 6;
    cnt[11][10][1] = 10;
    cnt[11][10][2] = 120;
    cnt[11][10][3] = 252;
    cnt[11][10][4] = 120;
    cnt[11][10][5] = 10;
    cnt[11][11][1] = 8;
    cnt[11][11][2] = 333;
    cnt[11][11][3] = 1428;
    cnt[11][11][4] = 1302;
    cnt[11][11][5] = 252;
    cnt[11][11][6] = 5;
    cnt[12][11][1] = 11;
    cnt[12][11][2] = 165;
    cnt[12][11][3] = 462;
    cnt[12][11][4] = 330;
    cnt[12][11][5] = 55;
    cnt[12][11][6] = 1;
    dp[0][0][0][0] = 1;
    for (int i = 0; i < 12; ++i) for (int x = 0; x < 12; ++x) for (int j = 0; j < 12; ++j) for (int k = 0; k < 12; ++k) {
        for (int ii = 2; ii < 13; ++ii) for (int jj = 1; jj < 12; ++jj) for (int kk = 1; kk < 12; ++kk) {
            int ni = i + ii - 1, nx = x + 1, nj = j + jj, nk = k + kk;
            if (ni >= 12 || nx >= 12 || nj >= 12 || nk >= 12)
                continue;
            add(dp[ni][nx][nj][nk], 1ll * dp[i][x][j][k] * cnt[ii][jj][kk] % mod);
        }
    }
    // 1 2 3 4 5
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        for (int i = 1; i < 12; ++i) for (int j = 1; j < 12; ++j) if (n - i >= j) {
            add(ans, 1ll * C(n - i, j) * dp[i][j][m][k] % mod);
        }
        cout << ans << '\n';
    }
}