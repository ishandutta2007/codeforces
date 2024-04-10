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
#define inf maxN * maxN * 3

struct card {
    char c;
    ll r, b;
};

int n, i, def;
card v[maxN];
ll more_red, more_blue;
short dp[1 << 16][2 * maxN * maxN + 11];
ll ans = inf;

void solve(int bg) {
    int i, j;
    int limit = 1 << n;
    int act_red, act_blue, cnt;
    int need_red, need_blue, need, bl, re, exc;
    vector<int> bits;

    bits.reserve(n);

    bg = max(bg, -def);
    bg = min(bg, def);

    for (i = 0; i < limit; i++)
        for (j= 0; j <= 2 * def; j++)
            dp[i][j] = inf;
    dp[0][def + bg] = 0;

    for (int conf = 0; conf < limit; conf++) {
        act_red = act_blue = 0;
        bits.clear();


        for (i = 0; i < n; i++) {
            if ( (conf >> i) & 1 )
                (v[i].c == 'R' ? act_red++ : act_blue++);
            else
                bits.pb(i);
        }

        for (cnt = 0; cnt <= 2 * def; cnt++) {
            if (dp[conf][cnt] >= inf) continue;

            if (conf == limit - 1)
                ans = min(ans, 1LL * dp[conf][cnt]);

            for (auto e : bits) {
                need_red = v[e].r;
                need_blue = v[e].b;

                bl = re = 0;

                if (cnt <= def)
                    bl = def - cnt;
                else
                    re = cnt - def;

                need = max(need_red - act_red - re, need_blue - act_blue - bl);
                need = max(need, 0);


                re += -max(0, need_red - act_red) + need;
                bl += -max(0, need_blue - act_blue) + need;

                exc = def + re - bl;
                exc = max(exc, 0);
                exc = min(exc, 2 * def);



                dp[conf ^ (1 << e)][exc] = min(1LL * dp[conf ^ (1 << e)][exc], 1LL * dp[conf][cnt] + need);
            }
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        scanf("%c %lld %lld\n", &v[i].c, &v[i].r, &v[i].b);
        more_red += max(0LL, v[i].r - n);
        more_blue += max(0LL, v[i].b - n);
        v[i].r = min(v[i].r, 1LL * n);
        v[i].b = min(v[i].b, 1LL * n);
    }

    def = n * n;
    solve(-more_red + more_blue);

    printf("%lld", ans + n + max(more_red, more_blue));


    return 0;
}