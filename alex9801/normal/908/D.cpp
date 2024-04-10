#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

const int mod = 1000000007;

int pro(int x, int a)
{
    if(a == 0)
        return 1;
    if(a % 2)
        return 1LL * pro(x, a - 1) * x % mod;
    int t = pro(x, a / 2);
    return 1LL * t * t % mod;
}

int mem[2010][1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int k, pa, pb, a, b, r, res, i, j;
    scanf("%d%d%d", &k, &pa, &pb);

    r = pro(pa + pb, mod - 2);
    a = 1LL * pa * r % mod;
    b = 1LL * pb * r % mod;

    int rb = 1LL * (pa + pb) * pro(pb, mod - 2) % mod;

    mem[0][1] = 1;

    for(j = 1; j < k; j++)
    {
        for(i = 0; i < k; i++)
        {
            mem[i][j + 1] = (mem[i][j + 1] + 1LL * mem[i][j] * a) % mod;
            mem[i + j][j] = (mem[i + j][j] + 1LL * mem[i][j] * b) % mod;
        }
    }

    res = 0;
    for(j = 1; j < k; j++)
        for(i = k; i <= 2 * k; i++)
            res = (res + 1LL * mem[i][j] * i) % mod;

    for(i = 0; i < k; i++)
        res = (res + 1LL * mem[i][k] * ((i + k + 1LL * a * rb % mod)) % mod) % mod;
    
    printf("%d", res);
    return 0;
}