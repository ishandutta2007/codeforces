#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 4e3 + 2;
struct asd{
    int t, d;
};

asd a[maxn];
int dp [maxn][maxn];

bool f (asd a, asd b){
    return a.t < b.t;
}

int main(){
    int n, k, i, ans = 0, j;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%d%d", &a[i].t, &a[i].d);
    sort(a, a + n, f);
    for (i = 1; i <= n; i++)
        for (j = 0; j <= k; j++){
            if (dp[i - 1][j] > a[i - 1].t)
                dp[i][j] = dp[i - 1][j] + a[i - 1].d;
            else
                dp[i][j] = a[i - 1].t + a[i - 1].d - 1;

            if (j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    for (i = 0; i < n; i++)
        ans = max(ans, a[i].t - dp[i][k] - 1);
    
    ans = max(ans, 86400 - dp[n][k]);
    cout << ans;
    return 0;
}