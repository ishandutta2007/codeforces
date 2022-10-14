#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 100;

struct item {
    int w, x;
    lli v;
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, q, n = 6, w;
    lli f[n];
    cin >> k;
    fop (i,0,n) cin >> f[i];
    cin >> q >> w;
    vector <item> B(n);
    for (int i = 0; i < n; ++i) B[i].w = i ? B[i - 1].w * 10 : 3;
    for (int i = 0; i < n; ++i) B[i].v = f[i];
    for (int i = 0; i < n; ++i) B[i].x = 3 * (k - 1);
    vector <vector <lli>> dp(n + 1, vector <lli>(w + 1, -1ll << 60));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int r = 0; r < B[i].w; ++r) {
            deque <int> dq;
            for (int j = r; j <= w; j += B[i].w) {
                while (dq.size() && dp[i][dq.back()] - B[i].v * (dq.back() / B[i].w) <= dp[i][j] - B[i].v * (j / B[i].w)) dq.pop_back();
                dq.push_back(j);
                while (dq.size() && (dq.front() / B[i].w) + B[i].x < j / B[i].w) dq.pop_front();
                assert(dq.size());
                dp[i + 1][j] = dp[i][dq.front()] + B[i].v * (j / B[i].w) - B[i].v * (dq.front() / B[i].w);
            }
        }
    }
    lli ans = 0;
    for (int i = 0; i <= w; ++i) {
        int a = w - i;
        for (int j = 0; j < n; ++j) {
            int r = a % 10;
            if (r % 3 == 0) {
                dp[n][i] += f[j] * (r / 3);
            }
            a /= 10;
        }
    }
    cout << *max_element(all(dp[n])) << endl;
}