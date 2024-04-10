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

#define maxN 5017

int n, i, j, k, to, bit, limit, sz;
char s[maxN];

bool dp[maxN][maxN];
pair<int, int> prov[maxN][maxN];
int pre[maxN];

bool deny[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    if (n == 1) {
        printf("%c", s[1]);
        return 0;
    }

    for (bit = 0; (1 << bit) <= n; bit++); bit -= 2;
    limit = (1 << bit) << 1;

    for (i = 1; i <= limit; i++) pre[i] = i;

    sz = n - pre[limit - 1];

    dp[0][0] = true;
    for (i = 0; i <= sz; i++) {
        char best = 'z';

        for (j = 0; j < limit; j++) {
            if (dp[i][j] == false) continue;

            dp[i + 1][j] = true;
            prov[i + 1][j] = prov[i][j];
            best = min(best, s[i + pre[j] + 1]);

            for (k = 0; k <= bit; k++) {
                if ((j >> k) & 1) continue;
                to = j | (1 << k);

                if (dp[i][to] == false) {
                    dp[i][to] = true;
                    prov[i][to] = mp(k, i + pre[j] + 1);
                }
            }
        }

        for (j = 0; j < limit; j++) {
            if (!dp[i + 1][j]) continue;
            if (s[i + pre[j] + 1] != best)
                dp[i + 1][j] = false;
        }
    }

    i = sz; j = limit - 1;
    while (j != 0) {
        int bb = prov[i][j].first;
        int pos = prov[i][j].second;

        for (i = 0; i < (1 << bb); i++) deny[pos + i] = true;

        int new_conf = j ^ (1 << bb);
        int new_pos = pos - 1 - pre[new_conf];

        i = new_pos;
        j = new_conf;
    }

    for (i = 1; i <= n; i++)
        if (!deny[i])
            printf("%c", s[i]);





    return 0;
}