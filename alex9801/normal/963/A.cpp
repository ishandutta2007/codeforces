#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

char arr[100010];
const int mod = 1000000009;

int ipow(int a, int x)
{
    if(a < 0)
        return ipow((a % mod + mod) % mod, x);

    if(x == 0)
        return 1;
    if(x % 2)
        return 1LL * ipow(a, x - 1) * a % mod;
    int t = ipow(a, x / 2);
    return 1LL * t * t % mod;
}

int inv(int x)
{
    return ipow(x, mod - 2);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, a, b, k, i;
    scanf("%d%d%d%d%s", &n, &a, &b, &k, arr);

    int d = (n + 1) / k;
    int r = 1LL * ipow(b, k) * inv(ipow(a, k)) % mod;
    int c = 1LL * (ipow(r, d) + mod - 1) * inv(r + mod - 1) % mod;

    int res = 0;
    for(i = 0; i < k; i++)
    {
        int fir = 1LL * ipow(a, n - i) * ipow(b, i) % mod;

        int sum;
        if(r == 1)
            sum = 1LL * fir * d % mod;
        else if(r == mod - 1)
        {
            if(d % 2 == 0)
                sum = 0;
            else
                sum = fir;
        }
        else
            sum = 1LL * fir * c % mod;

        if(arr[i] == '+')
            res = (res + sum) % mod;
        else
            res = (res + mod - sum) % mod;
    }

    res = (res % mod + mod) % mod;
    printf("%d\n", res);
    return 0;
}