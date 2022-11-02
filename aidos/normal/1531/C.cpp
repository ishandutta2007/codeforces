#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
int n;
bool t[222][222];
int dp[222][222];
int pr[222][222];
bool check(int len, int n) {
    if(!dp[len][n]) return false;
    vector<int>a;
    int cur = pr[len][n];
    while(n > 0) {
        a.push_back(cur+1);
        n -= 2 * cur + 1;
        cur = pr[cur][n];
    }
    if(n > 0) return false;
    int stx = len-1;
    int sty = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i]; j++) {
            t[stx - j][sty] = 1;
            t[stx][sty+j] = 1;
        }
        stx--;
        sty++;
    }
    cout << len << "\n";
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(t[i][j]) cout << 'o';
            else cout << '.';
        }
        cout << "\n";
    }
    return true;
}
void solve() {
    cin >> n;
    dp[1][1] = 1;
    dp[0][0] = 1;
    pr[1][1] = 0;
    dp[1][0] = 1;
    for(int i = 2; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            if(dp[i-1][j]) {
                dp[i][j] = 1;
                pr[i][j] = pr[i-1][j];
            }
            if(j >= 2 * (i-1) + 1 && dp[i-1][j - 2 * (i-1) - 1]) {
                dp[i][j] = 1;
                pr[i][j] = i-1;
            }

        }
    }
    //cout << dp[3][3] << "\n";

    for(int len = 1; len <= 100; len++) {
        if(check(len, n)) {
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d:\n", i);
        solve();
    }

    return 0;
}