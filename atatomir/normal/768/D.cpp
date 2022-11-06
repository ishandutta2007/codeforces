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

#define maxN 1024
#define eps 1e-7

int q, k, i, j, x, pos;
vector< pair<int, int> > Q;

int ss, dd;
double dp[2][maxN];
double nxt[maxN], here[maxN];
int ans[maxN];


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &k, &q);
    for (i = 1; i <= q; i++) {
        scanf("%d", &x);
        Q.pb(mp(x, i));

        if (k == 1) printf("1\n");
    }

    if (k == 1) return 0;


    sort(Q.begin(), Q.end());

    ss = 0; dd = 1;
    dp[ss][1] = 1.00;

    for (i = 1; i <= k; i++) {
        here[i] = 1.00 * i / k;
        nxt[i] = 1.00 - here[i];
    }

    pos = 0;
    for (i = 2; pos < Q.size(); i++) {
        dp[dd][1] = dp[ss][1] * here[1];

        for (j = 2; j <= k; j++)
            dp[dd][j] = dp[ss][j - 1] * nxt[j - 1] + dp[ss][j] * here[j];

        while (pos < Q.size()) {
            if (dp[dd][k] < (1.00 * Q[pos].first - eps) / 2000.00) break;
            ans[Q[pos].second] = i;
            pos++;
        }

        swap(ss, dd);
    }

    for (i = 1; i <= q; i++)
        printf("%d\n", ans[i]);



    return 0;
}