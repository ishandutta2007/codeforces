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

#define maxN 300011

int n, i, j, bg, N;
ll k, x;
ll data[maxN], ini[maxN];
int ans;
int sgn = 1;

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

void clean() {
    int i;

    if (data[n] < 0) {
        sgn = -1;
        for (i = 0; i <= n; i++) data[i] *= -1;
    }

    for (i = 0; i <= n; i++) {
        while (data[i] < 0) {
            data[i] += 2;
            data[i + 1]--;
        }
    }

    while (data[n] == 0) n--;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lld", &n, &k); N = n;
    for (i = 0; i <= n + 100; i++) {
        if (i <= n) {
            scanf("%lld", &x);
            data[i] += x;
            ini[i] = x;
        }

        int sgn = 1;
        if (data[i] < 0) {
            data[i] = -data[i];
            sgn = -1;
        }

        x = data[i];
        data[i] = 0;

        for (j = 0; j < 60; j++)
            if (x & (1LL << j))
                data[i + j] += sgn;
    }

    n += 100;
    while (data[n] == 0) n--;
    clean();

    for (bg = 0; data[bg] == 0; bg++);

    for (i = 0; i <= bg && i <= N; i++) {
        if (n - i + 1 > 60) continue;

        ll aux = 0;
        for (j = 0; i + j <= n; j++)
            if (data[i + j])
                aux |= 1LL << j;

        if (i == N && ini[i] - sgn * aux == 0) continue;
        if (abss(ini[i] - sgn * aux) <= k) ans++;
    }

    printf("%d", ans);

    return 0;
}