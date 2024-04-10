#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
int p[2 * maxn];
bitset < maxn > dp[maxn];
bitset < maxn > zero;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i) cin >> p[i];
        vector < int > weight;
        int stop = 2 * n + 1;
        for (int i = 2 * n; i >= 1; --i) {
            int pos;
            for (int j = 1; j <= 2 * n; ++j) {
                if (p[j] == i) pos = j;
            }
            if (pos < stop) weight.push_back(stop - pos), stop = pos;
        }
        for (int i = 1; i <= (int)weight.size(); ++i) dp[i] = zero;
        dp[0][0] = 1;
        for (int i = 1; i <= (int)weight.size(); ++i) {
            dp[i] = (dp[i - 1]|(dp[i - 1]<<weight[i - 1]));
        }
        if (dp[(int)weight.size()][n]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}