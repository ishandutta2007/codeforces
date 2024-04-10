#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int a[MAXN], b[MAXN], dp[2][MAXN];
vector<int> v[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        v[b[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dp[1][i] = v[a[i]].empty()? INF : v[a[i]][0];
        if(i + 1 + dp[1][i] + 1 + e <= s)
            ans = 1;
    }
    for(int ii = 2; ii * e <= s; ii++) {
        int i = ii & 1, pi = (ii - 1) & 1;
        dp[i][0] = INF;
        for(int j = 1; j < n; j++) {
            vector<int>::iterator it =
                upper_bound(v[a[j]].begin(), v[a[j]].end(), dp[pi][j - 1]);
            if(it == v[a[j]].end())
                dp[i][j] = INF;
            else
                dp[i][j] = *it;
            if(j + 1 + dp[i][j] + 1 + e * ii <= s)
                ans = ii;
            dp[pi][j] = min(dp[pi][j], dp[pi][j - 1]);
        }
    }
    cout << ans << '\n';
    return 0;
}