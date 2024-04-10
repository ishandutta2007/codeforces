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

#define maxN 3016

int n, i, j;
int v[maxN];
vector<int> norm;

ll dp[maxN][maxN];

ll abss(ll x) {
    if (x < 0)
        return -x;
    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        v[i] -= i;
        norm.pb(v[i]);
    }

    sort(norm.begin(), norm.end());
    norm.resize(unique(norm.begin(), norm.end()) - norm.begin());

    for (i = 0; i < norm.size(); i++) {
        dp[1][i] = abss(norm[i] - v[1]);
        if (i > 0)
            dp[1][i] = min(dp[1][i], dp[1][i - 1]);
    }

    for (i = 2; i <= n; i++) {
        for (j = 0; j < norm.size(); j++) {
            dp[i][j] = dp[i - 1][j] + abss(v[i] - norm[j]);
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    printf("%lld", dp[n][norm.size() - 1]);


    return 0;
}