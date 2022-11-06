#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll int

#define maxN 200011

ll n, m, i;
pair<ll, ll> p[maxN];
ll s[maxN];
ll act[maxN];

ll val, pos, id;
ll adap[maxN];

ll c, u;
ll ans[maxN];
bool used[maxN];


priority_queue< pair< pair<int, int>, int> > H;



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d", &p[i].first), p[i].second = i;
    for (i = 1; i <= m; i++) scanf("%d", &s[i]), act[i] = s[i], H.push(mp(mp(act[i], -s[i]), i));

    sort(p + 1, p + n + 1);
    for (i = n; i > 0 && !H.empty(); i--) {
        val = p[i].first;
        pos = p[i].second;

        while (act[H.top().second] > val) {
            id = H.top().second; H.pop();

            while (act[id] > val) {
                act[id] -= act[id] / 2;
                adap[id]++;
            }

            H.push(mp(mp(act[id], -s[id]), id));
        }

        if (act[H.top().second] < val) continue;

        id = H.top().second; H.pop();

        c++;
        u += adap[id];
        ans[pos] = id;
        used[id] = true;
    }

    for (i = 1; i <= m; i++)
        if (!used[i])
            adap[i] = 0;

    printf("%d %d\n", c, u);

    for (i = 1; i <= m; i++) printf("%d ", adap[i]);
    printf("\n");

    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");



    return 0;
}