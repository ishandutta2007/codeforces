#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n, k;
int a[maxn];
ll dp[maxn];
ll sum[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    deque<int> dq;
    for(int i=1; i<=n; i++) {
        while(dq.size() > 0 && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.front() + k <= i) dq.pop_front();
        dp[i] = dp[i-1] + a[i];
        sum[i] = sum[i-1] + a[i];
        if(i >= k) dp[i] = min(dp[i], dp[i-k] + sum[i] - sum[i-k] - a[dq.front()]);
    }
    cout << dp[n] << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}