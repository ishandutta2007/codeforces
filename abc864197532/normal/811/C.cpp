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
const int mod = 1e9 + 7, x = 864197532, N = 1001, logN = 18, K = 500, C = 1e9;

int dp[5001];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), al(5001, 0);
    fop (i,0,n) cin >> a[i], al[a[i]]++;
    fop (i,1,n + 1) dp[i] = -1 << 30;
    dp[0] = 0;
    fop (i,1,n + 1) {
        dp[i] = dp[i - 1];
        vector <int> cnt(5001, 0);
        int xorr = 0, tmp = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (cnt[a[j]] == 0) xorr ^= a[j], tmp++;
            cnt[a[j]]++;
            if (cnt[a[j]] == al[a[j]]) tmp--;
            if (tmp == 0) dp[i] = max(dp[i], dp[j] + xorr);
        }
    }
    cout << dp[n] << endl;
}