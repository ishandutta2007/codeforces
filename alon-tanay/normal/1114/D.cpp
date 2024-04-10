#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> cs;
    int last = -1;
    for(int i = 0; i < n; i ++) {
        int c; cin >> c;
        if(c != last) {
            cs.push_back(c);
            last = c;
        }
    }
    int s = cs.size();
    vector<vector<int>> dp(s+1,vector<int>(s+1));
    for(int i = 0; i < s; i ++) {
        dp[1][i] = 1;
    }
    for(int si = 2; si <= s; si ++) {
        for(int en = si - 1; en < s; en ++) {
            int st = en - si + 1;
            // cout << si << " " << st << " " << en << endl;
            if(cs[st] == cs[en]) {
                dp[si][st] = dp[si-2][st+1] + 1;
            } else {
                dp[si][st] = min(dp[si-1][st],dp[si-1][st+1]) + 1;
            }
        }
    }
    cout << (dp[s][0]-1) << endl;
    return 0;
}