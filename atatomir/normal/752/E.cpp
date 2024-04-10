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
#define maxVal 10000011

ll n, k, x, i, act, step, full, half;
ll cnt[maxVal];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &x);
        cnt[x]++;
        act++;
        full += x;
    }

    if (full < k) {
        printf("-1");
        return 0;
    }

    for (step = 1; act - cnt[step] >= k; act -= cnt[step++]);

    if (act >= k)
        ans = step;
    else
        ans = 0;

    for (i = 10000000; i > 0; i--) {
        if (cnt[i] == 0) continue;

        half = i >> 1;
        if (half <= ans) break;

        cnt[half] += cnt[i];
        cnt[(i + 1) >> 1] += cnt[i];
        act += cnt[i];
        cnt[i] = 0;

        for (; act - cnt[step] >= k; act -= cnt[step++]);
        ans = step;
    }

    printf("%lld", ans);





    return 0;
}