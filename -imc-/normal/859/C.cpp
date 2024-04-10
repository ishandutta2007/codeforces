#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

const int max_n = 51;

void relax(int& what, int with) {
    what = max(what, with);
}

void solve(bool read) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        s[i] = a[i] + (i ? s[i - 1] : 0);
    
    // cur, turn -> optimal 0 profit
    int dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    
    for (int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(dp[i + 1][1] + a[i], dp[i + 1][0]);
        dp[i][1] = min(dp[i + 1][0], dp[i + 1][1] + a[i]);
    }
    
    int sum = accumulate(all(a), 0);
    cout << sum - dp[0][0] << " " << dp[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}