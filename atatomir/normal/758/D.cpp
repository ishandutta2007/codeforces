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

#define maxN 111

ll base, n, i, l, r;
char nr[maxN];
ll act, last, pp, ppp, ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld\n%s", &base, nr + 1);
    n = strlen(nr + 1);

    ppp = 1;
    ans = 0;

    r = n;
    while (r > 0) {
        act = last = 0;
        for (pp = 1, l = r; l > 0; l--, pp *= 10) {
            act += pp * (nr[l] - '0');
            if (act >= base) break;

            last = act;
            if (pp >= base) break;
        }

        while (l + 1 < r && nr[l + 1] == '0') l++;
        r = l;

        ans += ppp * last;
        ppp *= base;
    }

    printf("%lld", ans);


    return 0;
}