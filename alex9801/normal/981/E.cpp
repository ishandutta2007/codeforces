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

vector<pair<int, int>> arr[10010];
int mem[10010];
bool chk[10010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, q, i, j;
    scanf("%d%d", &n, &q);
    for(i = 0; i < q; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        arr[x].push_back({ y, w });
    }

    mem[0] = n;
    for(i = 1; i <= n; i++)
    {
        for(auto &p : arr[i])
        {
            int y, w;
            y = p.first;
            w = p.second;

            for(j = n; j >= w; j--)
                mem[j] = max(mem[j], min(y, mem[j - w]));
        }

        for(j = 1; j <= n; j++)
        {
            if(mem[j] >= i)
                chk[j] = 1;
        }
    }

    vector<int> res;
    for(i = 1; i <= n; i++)
        if(chk[i])
            res.push_back(i);

    printf("%d\n", (int)res.size());
    for(int &x : res)
        printf("%d ", x);
    return 0;
}