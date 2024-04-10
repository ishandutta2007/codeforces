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

int n, k, i;
ll x;
ll vals[maxN];

set< pair<ll, int> > S;
int sgn = 1;

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%lld", &n, &k, &x);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &vals[i]);
        S.insert(mp( abss(vals[i]), i ));

        if (vals[i] < 0) sgn *= -1;
    }

    for (i = 1; i <= k; i++) {
        auto elem = S.begin();
        S.erase(elem);
        int pos = elem->second;

        if (vals[pos] < 0) sgn *= -1;
        if (sgn == 1)
            vals[pos] -= x;
        else
            vals[pos] += x;

        if (vals[pos] < 0) sgn *= -1;
        S.insert(mp( abss(vals[pos]), pos ));
    }

    for (i = 1; i <= n; i++)
        printf("%lld ", vals[i]);


    return 0;
}