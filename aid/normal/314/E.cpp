#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char c[MAXN];
unsigned int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    if(n & 1) {
        cout << 0 << '\n';
        return 0;
    }
    dp[0] = 1;
    for(int i = 1; i < n; i++)
        if(c[i] == '?')
            for(int j = (i - 1) / 2; j >= 0; j--)
                dp[j + 1] += dp[j];
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(c[i] == '?')
            cnt++;
    if(2 * cnt < n) {
        cout << 0 << '\n';
        return 0;
    }
    int cntBig = (n - cnt) + (n - 2 * (n - cnt)) / 2, cntSmall = cnt - cntBig;
    unsigned int ans = dp[cntBig];
    for(int i = 0; i < cntSmall; i++)
        ans = ans * 25u;
    cout << ans << '\n';
    return 0;
}