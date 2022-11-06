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

#define maxN 100011

const ll limit = 1LL << 59;

int n, i;
ll k, aux;
ll sum[maxN];
map< ll, int > M;
ll ans;

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lld", &n, &k);
    for (i = 1; i <= n; i++) scanf("%lld", &sum[i]), sum[i] += sum[i - 1];

    M[0]++;
    for (i = 1; i <= n; i++) {
        if (k == 1) {
            ans += 1LL * M[sum[i] - 1];
            M[sum[i]]++;
            continue;
        }

        if (k == -1) {
            ans += 1LL * M[sum[i] - 1];
            ans += 1LL * M[sum[i] + 1];
            M[sum[i]]++;
            continue;
        }

        for (aux = 1; abss(aux) <= limit; aux *= k) {
            ans += 1LL * M[sum[i] - aux];

            if ((limit / abss(aux)) < abss(k)) break;
        }

        M[sum[i]]++;
    }

    printf("%lld", ans);


    return 0;
}