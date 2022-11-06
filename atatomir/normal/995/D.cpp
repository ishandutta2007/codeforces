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

const int maxN = 18;

ll n, k, i, x, y, limit;
ll data[1 << maxN], ans;

void give() {
    double sol = (1.00 * ans) / (1.00 * limit);
    printf("%.10f\n", sol);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &k);
    limit = 1 << n;
    for (i = 0; i < limit; i++) scanf("%lld", &data[i]), ans += data[i];

    give();
    for (i = 1; i <= k; i++) {
        scanf("%lld%lld", &x, &y);
        ans -= data[x];
        data[x] = y;
        ans += y;
        give();
    }


    return 0;
}