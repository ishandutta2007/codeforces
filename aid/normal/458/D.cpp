#include <iostream>
#include <cmath>

using namespace std;

const int MAXM = 100 * 1000 + 5;;
long double lf[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(12);
    int n, m, k;
    cin >> n >> m >> k;
    lf[0] = 0;
    for(int i = 1; i <= m; i++)
        lf[i] = lf[i - 1] + logl(i);
    long double ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            if(k >= (i + j) * n - i * j)
                ans += expl(lf[n] - lf[i] - lf[n - i] +
                            lf[n] - lf[j] - lf[n - j] +
                            lf[m - (i + j) * n + i * j] -
                            lf[k - (i + j) * n + i * j] -
                            lf[m] + lf[k]);
    ans = min(ans, 1e99l);
    cout << ans << '\n';
    return 0;
}