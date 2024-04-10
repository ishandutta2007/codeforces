#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 998244353 ;
vector<pair<int, int> > a, b;
int n, r;
bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.first + x.second > y.first + y.second;
}
int dp[111][111];
void solve() {
    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        pair<int, int> x;
        cin >> x.first >> x.second;
        if(x.second >= 0) {
            a.emplace_back(x);
        } else{
            b.emplace_back(x);
        }
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i].first <= r) {
            r += a[i].second;
            cnt++;
        }
    }
    sort(b.begin(), b.end(), cmp);
    memset(dp, -1, sizeof dp);
    dp[0][0] = r;
    for(int i = 1; i <= b.size(); i++) {
        pair<int, int> x = b[i-1];
        for(int j = 0; j < i; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
        for(int j = 1; j <= i; j++) {
            if(dp[i-1][j-1] >= x.first) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x.second);
            }
        }
    }
    int cur = 0;
    for(int i = 0; i <= b.size(); i++) {
        if(dp[b.size()][i] >= 0) cur = i;
    }
    cout << cnt + cur << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}