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
#define ll long long

#define maxN 100011

int n, m, k, i;
ll p;
ll h[maxN], delta[maxN];
ll act[maxN];

priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > H;

bool check(ll st) {
    int i, rem;

    while (!H.empty()) H.pop();
    rem = 0;

    for (i = 1; i <= n; i++) {
        act[i] = st - delta[i];
        if (act[i] < 0) return false;
        H.push(mp( 1LL + (act[i]/delta[i]) , i));
    }

    for (int day = 1; day < m; day++) {
        rem += k;
        while (!H.empty()) {
            if (H.top().first != day) break;
            int node = H.top().second;
            H.pop();

            act[node] += p;
            H.push(mp(1LL + (act[node]/delta[node]), node));
            if (--rem < 0) return false;
        }
    }
    rem += k;

    for (i = 1; i <= n; i++) {
        while (act[i] - 1LL * (m - 1) * delta[i] < h[i]) {
            act[i] += p;
            if (--rem < 0) return false;
        }
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%lld", &n, &m, &k, &p);
    for (i = 1; i <= n; i++) scanf("%lld%lld", &h[i], &delta[i]);

    //cerr << check(14);
    //return 0;

    ll ans = -1;
    for (ll step = (1LL << 50); step > 0; step >>= 1)
        if (!check(ans + step))
            ans += step;

    printf("%lld", ans + 1);
    return 0;
}