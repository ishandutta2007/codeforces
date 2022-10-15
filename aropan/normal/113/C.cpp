#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

const int MAXN = 17320;
const int MAXF = 20000000;

int l, r, ans;
unsigned char F[MAXF];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> l >> r;
    for (int i = 3; i * i <= r; i += 2)
        if ((F[i >> 4] & (1 << ((i >> 1) & 7))) == 0)
            for (int j = i * i; j <= r; j += i + i)
                F[j >> 4] |= (1 << ((j >> 1) & 7));

    ans = l <= 2 && r >= 2;
    l = max(l, 3);
    for (int a = 1, aa; (aa = a * a) <= r; a++)
        for (int b = a + 1, x; (x = aa + b * b) <= r; b += 2)
        {
            if (x < l || (x & 1) == 0) continue;
            if ((F[x >> 4] & (1 << ((x >> 1) & 7))) == 0)
            {
                ans++;
                F[x >> 4] |= (1 << ((x >> 1) & 7));
            }
        }
    printf("%d\n", ans);
    return 0;
}