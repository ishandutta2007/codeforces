#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 555

int n, sum, i, j, val;
int v[maxN];

bool dp[maxN][maxN]; //! bigsum, smallsum
vector<int> ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &sum);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);

    dp[0][0] = true;
    for (int step = 1; step <= n; step++) {
        val = v[step];

        for (i = sum - val; i >= 0; i--) {
            for (j = 0; j <= i; j++) {
                dp[i + val][j] |= dp[i][j];
                dp[i + val][j + val] |= dp[i][j];
            }
        }
    }

    for (i = 0; i <= sum; i++)
        if (dp[sum][i] == true)
            ans.pb(i);

    printf("%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);

    return 0;
}