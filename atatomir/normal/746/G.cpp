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

#define maxN 200011

int n, t, k, i, j, ans, limit, dif, l, r;
int cnt[maxN];

int killed[maxN];


void no_sol() {
    printf("-1");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &t, &k);
    for (i = 1; i <= t; i++) scanf("%d", &cnt[i]);
    cnt[0] = 1;

    ans = 1;
    for (i = 1; i <= t; i++) {
        killed[i] = 1;
        ans--;
        ans += cnt[i];
    }

    if (ans < k) no_sol();

    for (i = 1; i <= t; i++) {
        limit = min(cnt[i], cnt[i - 1]);
        dif = ans - k;
        limit = min(limit, dif + 1);

        ans++;
        killed[i] = limit;
        ans -= limit;
    }

    if (ans != k) no_sol();

    printf("%d\n", n);

    l = r = 1;
    for (i = 1; i <= t; i++) {
        for (j = 1; j <= killed[i]; j++)
            printf("%d %d\n", l + j - 1, r + j);
        for (j = killed[i] + 1; j <= cnt[i]; j++)
            printf("%d %d\n", l, r + j);

        l = r + 1;
        r = r + cnt[i];
    }

    return 0;
}