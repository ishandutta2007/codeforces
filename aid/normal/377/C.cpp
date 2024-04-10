#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105, MAXM = 21, INF = 1000 * 1000 * 1000 + 5;
int s[MAXM], s1[MAXN], dp[1 << MAXM], m;
pair<char, char> turn[MAXM];

int getdp(int mask, int t) {
    if(dp[mask] != INF)
        return dp[mask];
    if(t == m)
        return dp[mask] = 0;
    if(turn[t].second == '1') {
        int res = -INF;
        for(int i = 0; i < m; i++)
            if(!((1 << i) & mask) && res < getdp(mask | (1 << i), t + 1) +
               (turn[t].first == 'p'? s[i] : 0))
               res = dp[mask | (1 << i)] + (turn[t].first == 'p'? s[i] : 0);
        return dp[mask] = res;
    }
    else {
        int res = INF;
        for(int i = 0; i < m; i++)
            if(!((1 << i) & mask) && res > getdp(mask | (1 << i), t + 1) -
               (turn[t].first == 'p'? s[i] : 0))
               res = dp[mask | (1 << i)] - (turn[t].first == 'p'? s[i] : 0);
        return dp[mask] = res;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s1[i];
    cin >> m;
    sort(s1, s1 + n);
    for(int i = 0; i < m; i++)
        s[i] = s1[n - m + i];
    for(int i = 0; i < m; i++)
        cin >> turn[i].first >> turn[i].second;
    for(int i = 0; i < 1 << m; i++)
        dp[i] = INF;
    cout << getdp(0, 0) << '\n';
    return 0;
}