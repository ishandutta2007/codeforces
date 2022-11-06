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

int arr[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - 1; j++)
        {
            if(abs(arr[j] - arr[j + 1]) >= 2)
            {
                printf("NO");
                return 0;
            }
        }

        int mx = 0;
        for(j = 1; j < n - i; j++)
            if(arr[j] > arr[mx])
                mx = j;

        for(j = mx; j < n - i - 1; j++)
            arr[j] = arr[j + 1];
    }
    printf("YES");
    
    return 0;
}