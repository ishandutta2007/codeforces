#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxQ 1024

int bits(ll x) {
    int ans = 0;
    while (x) {
        ans++;
        x >>= 1;
    }

    return ans;
}

struct way {
    ll x, y, lca;
    ll w;

    void comp_lca() {
        int b1 = bits(x);
        int b2 = bits(y);

        if (b1 < b2) {
            swap(b1, b2);
            swap(x, y);
        }

        ll xx = x;
        ll yy = y;
        while (b1 > b2) {
            b1--;
            xx >>= 1;
        }

        while (xx != yy) {
            xx >>= 1;
            yy >>= 1;
        }

        lca = xx;
    }
};

int n, i, op, cnt;
way W[maxQ], aux;
ll x, y;
map< ll, ll > M;





ll solve(ll x, ll y) {
    aux.x = x; aux.y = y;
    aux.comp_lca();

    ll ans = 0;

    for (ll node = aux.x; node != aux.lca; node >>= 1)
        ans += M[node];
    for (ll node = aux.y; node != aux.lca; node >>= 1)
        ans += M[node];

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    M.clear();

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &op);

        if (op == 1) {
            cnt++;
            scanf("%lld%lld%lld", &W[i].x, &W[i].y, &W[i].w);
            W[i].comp_lca();

            for (ll node = W[i].x; node != W[i].lca; node >>= 1)
                M[node] += W[i].w;

            for (ll node = W[i].y; node != W[i].lca; node >>= 1)
                M[node] += W[i].w;

        } else {
            scanf("%lld%lld", &x, &y);
            ll ans = solve(x, y);
            printf("%lld\n", ans);
        }
    }


    return 0;
}