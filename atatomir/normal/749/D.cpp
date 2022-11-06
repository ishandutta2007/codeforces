#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, q, j, i, who, bid, k, x, sz, sm, bg;
vector<int> bids[maxN];
int most[maxN];

set< pair<int, int> > S;
vector<int> rm;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &who, &bid);
        bids[who].pb(bid);
        most[who] = max(most[who], bid);
    }

    for (i = 1; i <= n; i++) {
        if (most[i] == 0) continue;
        S.insert(mp(most[i], i));
        sz++;
    }

    scanf("%d", &q);
    for (int qq = 1; qq <= q; qq++) {
        rm.clear();
        scanf("%d", &k);
        for (i = 1; i <= k; i++) {
            scanf("%d", &x);
            if (most[x] == 0) continue;

            rm.pb(x);
            S.erase(mp(most[x], x));
        }

        k = rm.size();
        if (k == sz) {
            printf("0 0\n");
        }
        else {
            if (k + 1 == sz) {
                who = S.begin()->second;
                printf("%d %d\n", who, bids[who][0]);
            } else {
                auto it = S.end();

                it--;
                bg = it->second;

                it--;
                sm = it->second;

                auto itt = lower_bound(bids[bg].begin(), bids[bg].end(), most[sm]);
                printf("%d %d\n", bg, *itt);
            }
        }



        for (auto e : rm)
            if (most[e] != 0)
                S.insert(mp(most[e], e));
    }



    return 0;
}