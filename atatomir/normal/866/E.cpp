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

#define maxN 16

int n, i, s_sum, carry_count, carry_conf, limit;
char s[maxN];
int difs[maxN];
ll dp[1 << maxN];
ll answer = 1LL << 60;
ll s_dec;

int to_dec(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'a' + 10;
}

void print_hex(int v) {
    if (v <= 9)
        printf("%d", v);
    else
        printf("%c", 'a' + v - 10);
}

void compute_difs() {
    int i;

    for (i = 1; i <= n; i++) {
        difs[i] = -to_dec(s[i]);
        if (carry_conf & (1 << (n - i))) difs[i] += 16;
        if (carry_conf & (1 << (n - i - 1))) difs[i] -= 1;
    }
}

void check() {
    int i, j, conf, act_sum;

    compute_difs();

    for (i = 0; i < limit; i++)
        dp[i] = 1LL << 60;

    for (i = 0; i < n; i++)
        dp[1 << i] = 0;

    for (conf = 1; conf < limit; conf++) {
        act_sum = 0;

        for (i = 0; i < n; i++)
            if (conf & (1 << i))
                act_sum += difs[i + 1];

        if (act_sum < 0 || act_sum > 15) continue;
        if (dp[conf] == 1LL << 60) continue;

        for (j = 0; j < n; j++) {
            if (conf & (1 << j)) continue;
            dp[conf | (1 << j)] = min(dp[conf | (1 << j)],
                                      dp[conf] + ((1LL * act_sum) << (4 * (n - j - 1))) );
        }
    }

    answer = min(answer, dp[limit - 1]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++)
        s_sum += to_dec(s[i]);

    if (s_sum % 15 != 0) {
        printf("NO");
        return 0;
    }

    limit = 1 << n;
    carry_count = s_sum / 15;
    for (carry_conf = 0; carry_conf < (limit >> 1); carry_conf++) {
        if (__builtin_popcount(carry_conf) != carry_count)
            continue;

        check();
    }

    if (answer == 1LL << 60) {
        printf("NO");
        return 0;
    }

    for (i = 1; i <= n; i++)
        s_dec = (s_dec << 4) | to_dec(s[i]);

    answer -= s_dec;

    for (i = n - 1; i >= 0; i--)
        print_hex( (answer >> (4 * i)) & 15  );


    return 0;
}