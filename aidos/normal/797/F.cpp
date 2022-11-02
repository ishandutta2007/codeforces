#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e3 + 100;
ll dp[maxn];
ll d[maxn];
int n, m;
pair<int, int> y[maxn];
int x[maxn];
ll sum[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int s = 0;
    for(int j = 0; j < m; j++) {
        cin >> y[j].first >> y[j].second;
        s += y[j].second;
    }
    sort(x, x + n);
    sort(y, y + m);
    for(int i = 0; i <= n; i++) {
        dp[i] = 1ll<<60;
    }
    if(s < n) {
        cout << -1 << "\n";
        return;
    }
    dp[0] = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= n; j++) {
            d[j] = dp[j];
            dp[j] = 1ll<<60;
        }
        dp[0] = 0;
        for(int j = 1; j <= n; j++) {
            sum[j] = sum[j-1] + abs(y[i].first - x[j-1]);
        }
        deque<pair<int, ll>>dq;
        for(int j = 0; j <= n; j++) {
            ll cur = d[j] - sum[j];
            while(dq.size() > 0 && dq.back().second > cur) {
                dq.pop_back();
            }
            if(dq.size() > 0 && dq.front().first + y[i].second < j) dq.pop_front();
            dq.push_back(make_pair(j, cur));
            dp[j] = dq.front().second + sum[j];
        }
    }
    cout << dp[n] << "\n";
}
int main(){
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}