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

#define maxN 1000011

const int limit = 1000000;

int q, i, l, r, k;
int dp[maxN];
int sum[maxN][11];

void pre() {
    int i, aux, to, cf;

    for (i = 1; i < 10; i++) dp[i] = i;
    for (i = 10; i <= limit; i++) {
        aux = i;
        to = 1;

        while (aux > 0) {
            cf = aux % 10;
            aux /= 10;
            if (cf) to *= cf;
        }

        dp[i] = dp[to];
    }

    for (i = 1; i <= limit; i++) {
        memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
        if (dp[i] <= 9) sum[i][dp[i]]++;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", sum[r][k] - sum[l - 1][k]);
    }


    return 0;
}