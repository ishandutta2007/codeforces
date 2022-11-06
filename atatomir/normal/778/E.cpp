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
#define sigma 11
#define inf 1LL << 60

int n, dim, i, j, global, d1;
char s[maxN];
int patt[maxN], dd[maxN];
int nr[maxN][maxN];
int cost[sigma];

ll dp[maxN][maxN];

vector<int> radix[sigma], ord;
int cnt[sigma];

void rev(char* a, char *b) {
    while (a < b) {
        swap(*a, *b);
        a++; b--;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n", s + 1);
    dim = strlen(s + 1);
    rev(s + 1, s + dim);
    for (i = 1; i <= dim; i++) {
        if (s[i] == '?')
            patt[i] = -1;
        else
            patt[i] = s[i] - '0';
    }

    d1 = dim;
    global = dim;
    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s\n", s + 1);
        dim = dd[i] = strlen(s + 1);
        global = max(global, dim);
        rev(s + 1, s + dim);

        for (j = 1; j <= dim; j++)
            nr[i][j] = s[j] - '0';

        dd[i] = max(dd[i], d1);
    }

    for (i = 0; i < 10; i++) scanf("%d", &cost[i]);
    for (i = 0; i <= dim; i++)
        for (j = 0; j <= n; j++)
            dp[i][j] = -inf;

    dim = global;
    for (i = 1; i <= n; i++) ord.pb(i);
    dp[1][0] = 0;

    for (i = 1; i <= dim; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (j = 1; j <= n; j++)
            if (nr[j][i] != 0 || dd[j] >= i)
                cnt[ nr[j][i] ]++;

        for (j = 0; j <= n; j++) {
            if (j > 0) {
                if (nr[ ord[j - 1] ][i] != 0 || dd[ ord[j - 1] ] >= i)
                    cnt[ nr[ ord[j - 1] ][i] ]--;
                cnt[ nr[ ord[j - 1] ][i] + 1 ]++;
            }

            if (dp[i][j] < 0) continue;

            for (int cf = 0; cf < 10; cf++) {
                if (patt[i] != -1 && patt[i] != cf) continue;
                if (i == d1 && cf == 0) continue;

                int pl = 0;
                ll new_sum = dp[i][j];

                for (int act = 0; act < 11; act++) {
                    int go = act + cf;

                    pl += (go / 10) * cnt[act];
                    go %= 10;

                    new_sum += 1LL * cost[go] * cnt[act];
                }

                dp[i + 1][pl] = max(dp[i + 1][pl], new_sum);
            }
        }

        for (j = 0; j < 10; j++) radix[j].clear();
        for (auto e : ord)
            radix[ nr[e][i] ].pb(e);

        ord.clear();
        for (j = 9; j >= 0; j--)
            for (auto e : radix[j])
                ord.pb(e);
    }

    ll ans = 0;
    for (i = 0; i <= n; i++)
        ans = max(ans, dp[dim + 1][i] + 1LL * cost[1] * i);

    printf("%lld", ans);


    return 0;
}