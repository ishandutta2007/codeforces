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

const int maxN = 100011;

ll n, i, j, U;
ll E[maxN];

bool any = false;
double ans = 0.00;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &U);
    for (i = 1; i <= n; i++) scanf("%lld", &E[i]);

    for (i = 1; i <= n; i++) {
        j = max(j, i);

        while (j + 1 <= n && E[j + 1] - E[i] <= U) j++;
        if (j - i + 1 >= 3) {
            any = true;
            ans = max(ans, (1.00 * E[j] - E[i + 1]) / (1.00 * E[j] - E[i]));
        }
    }

    if (!any)
        printf("-1");
    else
        printf("%.20lf", ans);


    return 0;
}