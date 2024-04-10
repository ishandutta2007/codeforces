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
#include <cmath>

using namespace std;

char arr[200][200];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i, j, k;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%s", arr[i]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(arr[i][j] == 'W')
                continue;

            for(k = j; k < m; k++)
                if(arr[i][k] == 'W')
                    break;

            int s = k - j;

            printf("%d %d\n", i + s / 2 + 1, j + s / 2 + 1);
            return 0;
        }
    }

    return 0;
}