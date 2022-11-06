#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

int a, b, k;
double ans, ans2;

int main()
{
    //freopen("input.in","r",stdin);

    scanf("%d %d", &a, &b);
    if (a < b) {
        printf("-1");
        return 0;
    }
    if (a == b) {
        printf("%d", a);
        return 0;
    }

    a -= b;
    k = a / (2 * b);
    ans = 1.00 * a / (2.00 * k);

    a += 2 * b;
    k = a / (2 * b);
    ans2 = 1.00 * a / (2.00 * k);

    ans = min(ans, ans2);

    printf("%.10lf", ans);

    return 0;
}