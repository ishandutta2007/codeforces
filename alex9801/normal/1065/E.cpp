#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

int arr[200010];
const int mod = 998244353;

int ipow(int a, int p)
{
    if(p == 0)
        return 1;
    if(p % 2)
        return 1LL * ipow(a, p - 1) * a % mod;
    int r = ipow(a, p / 2);
    return 1LL * r * r % mod;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, a, i;
    scanf("%d%d%d", &n, &m, &a);
    for(i = 1; i <= m; i++)
        scanf("%d", &arr[i]);

    int r = ipow(a, n - 2 * arr[m]);
    for(i = 1; i <= m; i++)
    {
        int l = arr[i] - arr[i - 1];

        int x = ipow(a, l);
        int y = (ipow(a, 2 * l) + (mod - x)) % mod;
        if(y % 2)
            y += mod;
        y /= 2;

        r = 1LL * r * (x + y) % mod;
    }

    printf("%d\n", r);
    return 0;
}