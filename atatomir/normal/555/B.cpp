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

struct intr {
    ll l, r;
    int id;

    bool operator<(const intr& who) const {
        return mp(l, r) < mp(who.l, who.r);
    }
};

int n, m, i, p;
pair<ll, ll> island[maxN];
intr v[maxN];
pair<ll, int> pos[maxN];
set< pair<ll, int> > S;
int ans[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%lld%lld", &island[i].first, &island[i].second);
    for (i = 2; i <= n; i++) {
        v[i - 1].l = island[i].first - island[i - 1].second;
        v[i - 1].r = island[i].second - island[i - 1].first;
        v[i - 1].id = i - 1;
    }
    n--;

    for (i = 1; i <= m; i++) scanf("%lld", &pos[i].first), pos[i].second = i;

    sort(v + 1, v + n + 1);
    sort(pos + 1, pos + m + 1);

    p = 1;
    for (i = 1; i <= m; i++) {
        while (p <= n && v[p].l <= pos[i].first) {
            S.insert(mp(v[p].r, v[p].id));
            p++;
        }

        if (S.empty()) continue;
        auto it = S.begin();
        if (it->first < pos[i].first) {
            printf("No\n");
            return 0;
        }

        ans[it->second] = pos[i].second;
        S.erase(it);
    }

    for (i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);


    return 0;
}