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

#define maxN 200011
const ll def = 200000;

ll n, i, x, l, r;
vector<ll> aux;
ll sum[maxN];
ll ans, act;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &x);
        aux.pb(x);
        sum[x]++;
    }

    for (i = 1; i <= def; i++) sum[i] += sum[i - 1];
    sort(aux.begin(), aux.end());
    aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

    for (auto e : aux) {
        act = 0;

        for (l = e; l <= def; l += e) {
            r = min(def, l + e - 1);
            act += l * (sum[r] - sum[l - 1]);
        }

        ans = max(ans, act);
    }

    printf("%lld", ans);


    return 0;
}