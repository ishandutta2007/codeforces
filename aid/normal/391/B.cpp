#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1005;
int dp[MAXN];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.length(), ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        for(int j = i + 1; j < n; j += 2)
            if(s[j] == s[i]) {
                dp[i] = dp[j] + 1;
                break;
            }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}