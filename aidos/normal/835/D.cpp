#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
string s;
int n;
bool d[5050][5050];
int dp[5050][5050];
int cnt[maxn];
void solve() {
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++) {
        d[i][i] = 1;
        dp[i][i] = 1;
        if(i + 1 < n && s[i] == s[i + 1]) {
            d[i][i + 1] = 1;
            dp[i][i + 1] = 2;
        }
    }
    for(int len = 2; len <= n; len++) {
        for(int i = len; i < n; i++) {
            if(s[i] == s[i - len] && d[i-len + 1][i - 1]) {
                d[i - len][i] = 1;
            }
        }
    }
    for(int len = 2; len <= n; len++) {
        for(int i = len; i < n; i++) {
            if(d[i-len][i]) {
                dp[i-len][i] = 1;
                int L = (len + 1)/2;
                if(d[i - L + 1][i]) {
                    dp[i-len][i] = dp[i-L+1][i] + 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cnt[dp[i][j]]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        int cur = 0;
        for(int j = i; j <= n; j++) {
            cur += cnt[j];
        }
        cout << cur << " ";
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}