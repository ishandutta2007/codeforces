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

int gcd(int x, int y)
{
    return x ? gcd(y%x, x) : y;
}

int arr[2010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, a, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    a = arr[0];
    for(i = 1; i < n; i++)
        a = gcd(a, arr[i]);

    if(a > 1)
    {
        printf("-1");
        return 0;
    }

    a = 0;
    for(i = 0; i < n; i++)
        if(arr[i] == 1)
            a++;

    if(a > 0)
    {
        printf("%d", n - a);
        return 0;
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            arr[j] = gcd(arr[j], arr[j + 1]);
            if(arr[j] == 1)
            {
                printf("%d", n + i);
                return 0;
            }
        }
    }

    printf("-1");
    return 0;
}