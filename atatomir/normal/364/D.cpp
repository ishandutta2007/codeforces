#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <unordered_map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011

int n, i;
ll a[maxN];
ll ans = 1;

pair<ll, int> data[maxN];
unordered_map<ll, int> M;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve(ll base) {
    int i, j, cnt, zz;
    ll aux, d;

    cnt = 0;
    M.clear();

    for (d = 1; d * d <= base; d++) {
        if (base % d) continue;
        M[d] = ++cnt; data[cnt] = mp(d, 0);
        M[base / d] = ++cnt; data[cnt] = mp(base / d, 0);
    }

    for (i = 1; i <= n; i++) {
        aux = gcd(base, a[i]);
        data[ M[aux] ].second++;
    }

    for (i = 1; i <= cnt; i++) {
        zz = 0;

        for (j = 1; j <= cnt; j++) {
            if (data[j].first % data[i].first == 0)
                zz += data[j].second;
        }

        if (zz * 2 >= n) ans = max(ans, data[i].first);
    }
}

int main()
{
    srand(time(NULL));
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    random_shuffle(a + 1, a + n + 1);
    random_shuffle(a + 1, a + n + 1);
    random_shuffle(a + 1, a + n + 1);

    for (int checks = 0; checks < 8; checks++)
        solve(a[ (rand() % n) + 1 ]);

    if (ans == 1) solve(999999999999);

    printf("%lld", ans);

    return 0;
}