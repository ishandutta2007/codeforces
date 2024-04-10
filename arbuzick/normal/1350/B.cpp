#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[30][30];
long double pi = 3.1415926535;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> s(n+1);
        for(int i = 1; i <= n; ++i)
            cin >> s[i];
        vector<int> dp(n+1, 1);
        for(int i = 1; i <= n; ++i){
            for(int j = i*2; j <= n; j += i)
                if(s[i] < s[j])
                    dp[j] = max(dp[j], dp[i]+1);
        }
        int ans = 1;
        for(int i = 1; i <= n; ++i)
            ans = max(ans, dp[i]);
        cout << ans << '\n';
    }
    return 0;
}