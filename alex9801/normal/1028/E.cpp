#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

int arr[150000];
long long res[150000];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bool ok = 0;
    for(i = 0; i < n - 1; i++)
    {
        if(arr[i] != arr[i + 1])
        {
            ok = 1;
            break;
        }
    }

    if(!ok)
    {
        if(arr[0] == 0)
        {
            printf("YES\n");
            for(i = 0; i < n; i++)
                printf("1 ");
            return 0;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }

    arr[n] = arr[0];
    int p;
    for(i = 0; i < n; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            p = (i + 1) % n;
            break;
        }
    }

    res[p] = arr[p];

    for(i = 1; i < n; i++)
    {
        int t = (p - i + n) % n;
        int t0 = (t - 1 + n) % n;
        int t2 = (t + 1) % n;

        long long k = (arr[t0] - arr[t]) / res[t2];
        while(arr[t] + res[t2] * (k - 1) > arr[t0])
            k--;
        while(arr[t] + res[t2] * k <= arr[t0])
            k++;

        res[t] = arr[t] + res[t2] * k;
    }

    printf("YES\n");
    for(i = 0; i < n; i++)
        printf("%lld ", res[i]);

    return 0;
}