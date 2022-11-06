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

int deg[100010];
vector<int> arr;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        deg[x]++;
        deg[y]++;
    }

    int x = -1;
    for(i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
            arr.push_back(i);
        else if(deg[i] >= 3)
        {
            if(x != -1)
            {
                printf("No");
                return 0;
            }
            x = i;
        }
    }

    printf("Yes\n");
    if(x == -1)
    {
        assert(arr.size() == 2);
        printf("1\n%d %d", arr[0], arr[1]);
    }
    else
    {
        printf("%d\n", (int)arr.size());
        for(int &y : arr)
            printf("%d %d\n", x, y);
    }
    return 0;
}