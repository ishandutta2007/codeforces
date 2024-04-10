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

#define maxN 500011

struct rect {
    ll x1, y1, x2, y2;
};

int n, i;
rect R[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    printf("YES\n");

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld%lld%lld", &R[i].x1, &R[i].y1, &R[i].x2, &R[i].y2);

        if (R[i].x1 > R[i].x2) swap(R[i].x1, R[i].x2);
        if (R[i].y1 > R[i].y2) swap(R[i].y1, R[i].y2);

        int ans = 1;
        if ((R[i].x1 + (1LL << 50)) & 1) ans += 1;
        if ((R[i].y1 + (1LL << 50)) & 1) ans += 2;

        printf("%d\n", ans);
    }


    return 0;
}