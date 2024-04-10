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

#define maxN 777
#define maxM 200011

int n, m, i;
ll a[maxN], q[maxM];
ll need[maxN];
ll x, ans, step;

priority_queue<ll> H;
vector<ll> aux;

ll check(ll delta) {
    static int i;
    int ans = 0;

    while (!H.empty()) H.pop();
    for (i = 1; i <= n; i++) {
        delta += a[i];
        if (a[i] < 0) H.push(-a[i]);

        if (delta < 0) {
            delta += H.top();
            H.pop();
            ans++;
        }
    }

    return ans;
}

ll compute_need(int cnt) {
    ll ans = -1;

    for (ll step = (1LL << 17); step > 0; step >>= 1)
        if (ans + step < aux.size())
            if (check( aux[ans + step] ) > cnt)
                ans += step;

    if (ans + 1 == aux.size()) return 1LL << 60;
    return aux[ans + 1];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (i = 1; i <= m; i++) {
        scanf("%lld", &q[i]);
        aux.pb(q[i]);
    }

    sort(aux.begin(), aux.end());
    aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

    for (i = 0; i <= n; i++)
        need[i] = compute_need(i);

    for (i = 1; i <= m; i++) {
        x = q[i];

        ans = -1;
        for (step = (1 << 9); step > 0; step >>= 1)
            if (ans + step <= n)
                if (need[ans + step] > x)
                    ans += step;

        printf("%lld\n", ans + 1);
    }

    return 0;
}