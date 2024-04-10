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

#define maxN 100011

ll abss(ll x) {
    if (x > 0) return x;
    return -x;
}


struct plane {
    ll x, v;
    int id, t;

    bool operator<(const plane& who)const {
        return mp(abss(x * who.v), mp(t, -t * abss(v))) < mp(abss(v * who.x), mp(who.t, -t * abss(who.v)));
    }
};

ll n, w, i, j;
plane P[maxN], ord1[maxN], ord2[maxN];
int data[maxN], wh[maxN];
ll ans;

int get_tp(plane act) {
    if (act.x < 0) return -1;
    return 1;
}

int zrs(int x) {
    return (x ^ (x - 1)) & x;
}

void add(int x, int v) {
    while (x <= n) {
        data[x] += v;
        x += zrs(x);
    }
}

int sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += data[x];
        x -= zrs(x);
    }
    return ans;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &w);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld", &P[i].x, &P[i].v);
        P[i].id = i;
        P[i].t = get_tp(P[i]);

        ord1[i] = ord2[i] = P[i];
        if (P[i].t == -1) {
            ord1[i].v += w;
            ord2[i].v -= w;
        } else {
            ord1[i].v += w;
            ord2[i].v -= w;
        }

        ord2[i].t *= -1;
    }

    sort(ord1 + 1, ord1 + n + 1);
    sort(ord2 + 1, ord2 + n + 1);

    for (i = 1; i <= n; i++) wh[ord2[i].id] = i;

    for (i = n; i > 0; i--) {
        ans += 1LL * sum(wh[ord1[i].id]);
        add(wh[ord1[i].id], +1);
    }

    /*ans = 0;
    for (i = 1; i <= n; i++) {
        if (P[i].t != -1) continue;

        for (j = 1; j <= n; j++) {
            if (P[j].t != 1) continue;

            if (P[i].x * (P[j].v - w) <= P[j].x * (P[i].v + w))
                if (P[i].x * (P[j].v + w) >= P[j].x * (P[i].v - w))
                    ans++;
        }
    }*/

    printf("%lld", ans);


    return 0;
}