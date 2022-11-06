#include <cstdio>
#include <iostream>
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

int arr[30];
bool use[30];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, l, i, j;
    long long s, r;
    scanf("%d%d", &n, &l);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
        use[i] = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(1LL * arr[j] * (1LL << (i - j)) <= arr[i])
            {
                use[i] = 0;
                break;
            }
        }
    }

    r = 1LL << 62;
    s = 0;
    for(i = n - 1; i >= 0; i--)
    {
        if(!use[i])
            continue;

        long long t = 1LL << i;
        s += 1LL * arr[i] * (l / t);
        l %= t;
        r = min(r, s + arr[i]);
    }
    r = min(r, s);
    printf("%lld", r);
    return 0;
}