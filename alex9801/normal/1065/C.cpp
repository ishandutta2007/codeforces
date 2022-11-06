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

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, i;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);
    reverse(arr, arr + n);

    if(arr[0] == arr[n - 1])
    {
        puts("0");
        return 0;
    }

    int p = 0;
    int s = 0;
    int r = 0;
    for(i = arr[0] - 1; i >= 0; i--)
    {
        while(p < n - 1 && arr[p + 1] > i)
            p++;

        if(s + p + 1 > k)
        {
            r++;
            s = 0;
            if(p == n - 1)
                break;
        }

        s += p + 1;
    }
    if(r == 0 || s)
       r++;

    printf("%d\n", r);
    return 0;
}