#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5005;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
int l[MAXN], r[MAXN];
long long dp[2][2 * MAXN];
vector<int> x;

int get(int x, int l, int r) {
    if(x < l)
        return l - x;
    if(x > r)
        return x - r;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sx;
    cin >> n >> sx;
    x.push_back(sx);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        x.push_back(l[i]);
        x.push_back(r[i]);
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    int m = x.size();
    for(int i = 0; i < m; i++)
        dp[n & 1][i] = 0;
    for(int i = n - 1; i >= 0; i--) {
        int ii = (i & 1), pi = ((i + 1) & 1);
        long long p = INF;
        for(int j = 0; j < m; j++) {
            p = min(p, dp[pi][j] + get(x[j], l[i], r[i]) - x[j]);
            dp[ii][j] = p + x[j];
        }
        p = INF;
        for(int j = m - 1; j >= 0; j--) {
            p = min(p, dp[pi][j] + get(x[j], l[i], r[i]) + x[j]);
            dp[ii][j] = min(dp[ii][j], p - x[j]);
        }
    }
    for(int i = 0; i < m; i++)
        if(x[i] == sx) {
            cout << dp[0][i] << '\n';
            break;
        }
    return 0;
}