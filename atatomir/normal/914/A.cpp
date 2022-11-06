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

int n, i, x, ans, y;

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("*.out","w",stdout);

    ans = -1000000000;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);

        if (x < 0) {
            ans = max(ans, x);
            continue;
        }

        y = round(sqrt(x));
        if (y * y != x) ans = max(ans, x);
    }

    printf("%d", ans);


    return 0;
}