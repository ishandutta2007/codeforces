#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];
int prv[26][maxn];
int dp[maxn];
void solve() {
    string s, t;
    cin >> s;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < 26; j++) {
            prv[j][i] = prv[j][i-1];
        }
        prv[s[i-1] - 'a'][i] = i;
    }
    int ans = 0;
    for(int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i-1];
        int j = prv[s[i-1]-'a'][i-1];
        if(j > 0) dp[i] = max(dp[j-1] + 1, dp[i]);
    }
    cout << s.size() - dp[s.size()] * 2 << "\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}