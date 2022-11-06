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

#define maxOnes 111

ll s, act_sum, a, b, total, ones;
ll solution;

ll dp[maxOnes][2];
ll old[maxOnes][2];

ll solve(ll total, ll ones, ll a, ll b) {
    ll i, j;

    for (i = 0; i <= ones; i++) dp[i][0] = dp[i][1] = old[i][0] = old[i][1] = 0;

    dp[0][0] = 1;
    for (int bit = 0; (1LL << bit) <= total; bit++) {
        for (i = 0; i <= ones; i++) old[i][0] = dp[i][0], old[i][1] = dp[i][1], dp[i][0] = dp[i][1] = 0;

        for (int d1 = 0; d1 <= 1; d1++) {
            if (d1 == 1 && bit >= a) continue;

            for (int d2 = 0; d2 <= 1; d2++) {
                if (d2 == 1 && bit >= b) continue;

                for (int bonus = 0; bonus <= 1; bonus++) {
                    if ( (bonus + d1 + d2) % 2 != ((total >> bit) & 1) ) continue;

                    for (int bef = 0; bef <= 2 * bit; bef++) {
                        if (bef + d1 + d2 > ones) continue;
                        dp[bef + d1 + d2][(bonus + d1 + d2) / 2] += old[bef][bonus];
                    }
                }
            }
        }
    }

    return dp[ones][0];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &s);

    for (a = 0; a <= 50; a++) {
        for (b = 0; b <= 50; b++) {
            //cerr << a << ' ' << b << '\n';

            ll base = (1LL << (a + 1)) + (1LL << (b + 1)) - 3;
            ll lca = s / base;

            if (lca <= 0) continue;
            act_sum = s - lca * base - ((1LL << b) - 1);

            // way 1 -> x = 2 * x - pop_count(x)
            // 2 * le - pop_count(le) + 2 * ri - pop_count(ri) = act_sum
            for (ones = 0; ones <= a + b; ones++) {
                total = act_sum + ones;
                if (total < 0 || total % 2 == 1) continue;
                total >>= 1;

                solution += solve(total, ones, max(0LL, a - 1), max(0LL, b - 1));
            }
        }
    }

    printf("%lld", solution);


    return 0;
}