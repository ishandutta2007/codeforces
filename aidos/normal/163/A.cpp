#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n;
int dp[maxn];
int d[maxn];
string s, t;
void solve() {
    cin >> s >> t;
    s = "#" + s;
    for(int i = 0;i < t.size(); i++) {
        for(int j = s.size() - 1; j>0; j--) {
            if(t[i] == s[j]) {
                dp[j] = (dp[j] + dp[j-1] + 1) % mod;
            }
        }
        //for(int j = 0; j < s.size(); j++) cout << dp[j] << " ";
        //cout << "\n";
    }
    int ans = 0;
    for(int i = 1; i < s.size(); i++) ans = (ans + dp[i]) % mod;
    cout << ans << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}