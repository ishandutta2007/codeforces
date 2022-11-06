#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <iostream>
#include <functional>
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

int arr[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int p = 0;
    for(i = 1; i <= n; i++)
    {
        if(arr[i] < p)
            continue;

        if(arr[i] == p)
            p++;
        else
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("%d\n", -1);
    return 0;
}