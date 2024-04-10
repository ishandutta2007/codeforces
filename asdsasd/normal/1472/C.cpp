#include <bits/stdc++.h>
using namespace std;

long long dp[202000];

void solve(){
    int n;
    cin >> n;
    vector<int> a_s(n);
    for(int i = 0; i < n; i++){
        cin >> a_s[i];
        dp[i] = 0;
    }
    long long ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if (a_s[i] + i >= n) dp[i] = a_s[i];
        else dp[i] = a_s[i] + dp[i + a_s[i]];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}