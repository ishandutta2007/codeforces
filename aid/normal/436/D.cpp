#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, MAXM = 2005;
int a[MAXN], b[MAXM], l[MAXN], dp[MAXN], dp0[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    l[0] = 0;
    for(int i = 1; i < n; i++)
        l[i] = a[i] == a[i - 1] + 1? l[i - 1] : i;
    for(int i = 0; i < n; i++) {
        int p = upper_bound(b, b + m, a[i]) - b;
        if(i == l[i])
            dp[i] = max(dp[i], i? dp0[i - 1] : 0);
        else
            dp[i] = max(dp[i], dp[i - 1]);
        for(int j = 0; j < p; j++) {
            int k = a[i] - b[j];
            if(k <= i)
                dp[i] = max(dp[i], (l[i - k]? dp0[l[i - k] - 1] : 0) + p - j);
        }
        dp0[i] = max(dp0[i], dp[i]);
        for(int j = p; j < m; j++) {
            int k = b[j] - a[i];
            if(i + k < n)
                dp0[i + k] = max(dp0[i + k], dp[i] + j - p + 1);
        }
        dp0[i + 1] = max(dp0[i + 1], dp0[i]);
    }
    cout << dp0[n - 1] << '\n';
    return 0;
}