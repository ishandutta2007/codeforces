#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <cassert>

using namespace std;

long long arr[51];
long long sum[51];
bool mem[51][51];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, i, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);

    for(i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i];
    
    long long r = 0;
    for(int b = 55; b >= 0; b--)
    {
        r += 1LL << b;

        memset(mem, 0, sizeof mem);
        mem[0][0] = 1;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= k; j++)
            {
                for(int x = 0; x < i; x++)
                {
                    if(mem[x][j - 1] && ((sum[i] - sum[x]) & r) == r)
                    {
                        mem[i][j] = 1;
                        break;
                    }
                }
            }
        }

        if(!mem[n][k])
            r -= 1LL << b;
    }
    printf("%lld", r);
    return 0;
}