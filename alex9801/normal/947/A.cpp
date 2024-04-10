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

bool chk[1000010];
vector<int> pri;
vector<bool> dv;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);

    for(i = 2; i <= n; i++)
    {
        if(!chk[i])
        {
            pri.push_back(i);
            for(j = i; 1LL * i*j <= n; j++)
                chk[i*j] = 1;
        }
    }

    int s = -1;
    for(int p : pri)
        if(n % p == 0)
            s = p;

    int t = s * (n / s - 1) + 1;

    int res = n;
    for(int p : pri)
    {
        for(i = 2 * p; i <= n; i += p)
        {
            if(t <= i)
            {
                res = min(res, i - p + 1);
                break;
            }
        }
    }
    printf("%d", res);
    return 0;
}