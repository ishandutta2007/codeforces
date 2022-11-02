#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 109;
int dp[2][maxn][maxn * maxn];
int n;
int x[maxn];
int y[maxn];
int sum = 0;
int ans[maxn];
int inf = 1e9;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = (a - b) * 2 + b;
        y[i] = b;
        sum += b;
    }
    dp[1][0][0] = 0;
    for (int X = 1; X <= sum; X++)
        dp[1][0][X] = -inf;
    for (int i = 0; i < n; i++) {
        int e = (i % 2);
        for (int cnt = 0; cnt <= i + 1; cnt++)
            for (int X = 0; X <= sum; X++)
                dp[e][cnt][X] = -inf;
        for (int cnt = 0; cnt <= i; cnt++)
            for (int X = 0; X <= sum; X++) {
                int cur = dp[1 - e][cnt][X];
                if (cur > dp[e][cnt][X])
                    dp[e][cnt][X] = cur;
                if (cur + y[i] > dp[e][cnt + 1][min(X + x[i], sum)])
                    dp[e][cnt + 1][min(X + x[i], sum)] = cur + y[i];
            }
        for (int cnt = 0; cnt <= i + 1; cnt++)
            for (int X = 0; X <= sum; X++) {
                if (dp[e][cnt][X] + X > ans[cnt])
                    ans[cnt] = dp[e][cnt][X] + X;
            }
    }
    cout.precision(20);
    cout << fixed;
    for (int cnt = 1; cnt <= n; cnt++)
        cout << ((ld)ans[cnt]) / 2 << " ";
}