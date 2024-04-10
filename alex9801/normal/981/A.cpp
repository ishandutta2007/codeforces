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

using namespace std;

char arr[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j, k;
    scanf("%s", arr);
    n = strlen(arr);

    int r = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            bool ok = 0;
            for(k = i; k <= j; k++)
            {
                if(arr[k] != arr[i + j - k])
                {
                    ok = 1;
                    break;
                }
            }
            if(ok)
                r = max(r, j - i + 1);
        }
    }
    printf("%d", r);
    return 0;
}