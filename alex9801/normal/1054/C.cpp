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

int l[1010];
int r[1010];
vector<int> v[2010];

int res[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &l[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &r[i]);

    for(i = 1; i <= n; i++)
        v[l[i] + r[i]].push_back(i);

    int p = n;
    for(i = 0; i <= 2 * n; i++)
    {
        if(v[i].empty())
            continue;

        for(int x : v[i])
            res[x] = p;
        p--;
    }

    for(i = 1; i <= n; i++)
    {
        int c = 0;
        for(j = 1; j < i; j++)
            if(res[j] > res[i])
                c++;

        if(c != l[i])
        {
            puts("NO");
            return 0;
        }

        c = 0;
        for(j = i + 1; j <= n; j++)
            if(res[j] > res[i])
                c++;

        if(c != r[i])
        {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    for(i = 1; i <= n; i++)
        printf("%d ", res[i]);

    return 0;
}