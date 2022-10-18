#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[200005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int sum_c = 0;
    for (int i = 0; i < n; ++i){
        sum_c = 0;
        if (i != 0) dp[i] = dp[i - 1];
        for (int j = i; j > -1; --j){
            if (j < i && s[j] == '0') continue;
            sum_c += (s[j] - '0');
            int hp = 0;
            if (j != 0) hp = dp[j - 1];
            if (sum_c % 3 == 0){ dp[i] = max(dp[i], hp + 1);
            break;
            }
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}