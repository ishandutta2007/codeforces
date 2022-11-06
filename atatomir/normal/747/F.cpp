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

#define dig 14
#define maxN dig + 3
#define sigma 16

ll k, limit, i, how_many;
ll cnt[sigma];
ll comb[maxN][maxN];
ll sol[maxN];

ll dp[maxN][maxN], act;
bool first = true;

void pre() {
    ll i, j;

    for (i = 0; i < maxN; i++) {
        comb[i][0] = 1;
        for (j = 1; j <= i; j++)
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
}

void compute(ll rem) {
    ll i, j, nxt;

    if (rem == 0) {
        how_many = 1;
        return;
    }

    memset(dp, 0, sizeof(dp));
    for (i = 0; i <= cnt[1] && i <= rem; i++) dp[1][i] = 1;
    for (i = 1; i + 1 < sigma; i++) {
        for (j = 0; j <= rem; j++) {
            dp[i][j] = min(dp[i][j], k + 1);
            if (dp[i][j] == 0) continue;

            for (nxt = 0; j + nxt <= rem && nxt <= cnt[i + 1]; nxt++) {
                dp[i + 1][j + nxt] += dp[i][j] * comb[j + nxt][nxt];
                dp[i + 1][j + nxt] = min(dp[i + 1][j + nxt], k + 1);
            }
        }
    }


    bool inf_zero = (first && act == 0);

    i = sigma - 1;
    for (j = 0; j <= rem; j++) {
        dp[i][j] = min(dp[i][j], k + 1);
        if (dp[i][j] == 0) continue;

        for (nxt = 0; j + nxt <= rem && nxt <= cnt[0]; nxt++) {
            if (inf_zero) {
                if (j + nxt - 1 >= 0 && nxt >= 0) {
                    dp[0][j + nxt] += dp[i][j] * comb[j + nxt - 1][nxt];
                    dp[0][j + nxt] = min(dp[0][j + nxt], k + 1);
                }
            } else {
                dp[0][j + nxt] += dp[i][j] * comb[j + nxt][nxt];
                dp[0][j + nxt] = min(dp[0][j + nxt], k + 1);
            }
        }
    }

    if (inf_zero) {
        how_many = 1;
        for (i = 1; i <= rem; i++)
            how_many += dp[0][i];
        how_many = min(how_many, k + 1);
    } else {
        how_many = dp[0][rem];
    }
}

void print_val(int x) {
    if (x <= 9) {
        printf ("%d", x);
    } else {
        printf("%c", 'a' + x - 10);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &k, &limit);
    for (i = 0; i < sigma; i++) cnt[i] = limit;

    pre();

    k += 1;
    first = true;

    for (int step = dig; step > 0; step--) {
        for (act = 0; act < sigma; act++) {
            if (cnt[act] == 0) continue;

            if (!first || act != 0) cnt[act]--;
            how_many = 0;
            compute(step - 1);
            if (!first || act != 0) cnt[act]++;

            if (how_many >= k) {
                if (!first || act != 0) cnt[act]--;
                if (act > 0) first = false;

                sol[step] = act;
                break;
            }

            k -= how_many;
        }
    }

    for (i = dig; sol[i] == 0; i--);
    for (; i > 0; i--)
        print_val(sol[i]);


    return 0;
}