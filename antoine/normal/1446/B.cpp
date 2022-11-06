#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)5009;
int dp[MxN + 9][MxN + 9];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n, m,  ans = 0;
    string s, t;
    cin >> n >> m >> s >> t;
    for(int i = n; i >= 0; --i)
        for(int j = m; j >= 0; --j) {
            int &res = dp[i][j] = 0;
            if(i == n || j == m)
                continue;
            res = max(res, dp[i+1][j] - 1);
            res = max(res, dp[i][j+1] - 1);
            if(s[i] == t[j])
                res = max(res, dp[i+1][j+1] + 4 - 2);
            ans = max(ans, res);
        }
    cout << ans;

    return 0;
}