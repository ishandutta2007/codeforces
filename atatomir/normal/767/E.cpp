#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, i;
ll m;
ll c[maxN], w[maxN];
priority_queue< pair<ll, int> , vector< pair<ll, int> >, greater< pair<ll, int> > > H;

ll ans[maxN][2];
ll sol;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lld", &n, &m);
    for (i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for (i = 1; i <= n; i++) scanf("%lld", &w[i]);

    for (i = 1; i <= n; i++) {
        ans[i][0] = c[i] / 100;
        ans[i][1] = c[i] %= 100;

        m -= c[i];

        if (c[i] == 0) continue;
        H.push(mp(w[i] * (100 - c[i]), i));

        while (m < 0) {
            m += 100;
            ans[H.top().second][0]++;
            ans[H.top().second][1] = 0;
            sol += H.top().first;
            H.pop();
        }
    }

    printf("%lld\n", sol);
    for (i = 1; i <= n; i++)
        printf("%lld %lld\n", ans[i][0], ans[i][1]);


    return 0;
}