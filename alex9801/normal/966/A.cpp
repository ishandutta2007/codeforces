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

vector<int> ss, ee;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, s, e, v, i;
    scanf("%d%d%d%d%d", &n, &m, &s, &e, &v);
    for(i = 0; i < s; i++)
    {
        int x;
        scanf("%d", &x);
        ss.push_back(x);
    }
    for(i = 0; i < e; i++)
    {
        int x;
        scanf("%d", &x);
        ee.push_back(x);
    }
    int q;
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);

        int ans = 1e9;

        if(y1 == y2)
            ans = abs(x1 - x2);

        auto it = lower_bound(ss.begin(), ss.end(), x1);
        if(it != ss.end())
        {
            int x = *it;
            ans = min(ans, abs(x - x1) + abs(x - x2) + abs(y1 - y2));
        }

        if(it != ss.begin())
        {
            it--;
            int x = *it;
            ans = min(ans, abs(x - x1) + abs(x - x2) + abs(y1 - y2));
        }

        auto it2 = lower_bound(ee.begin(), ee.end(), x1);
        if(it2 != ee.end())
        {
            int x = *it2;
            ans = min(ans, abs(x - x1) + abs(x - x2) + (abs(y1 - y2) + v - 1) / v);
        }

        if(it2 != ee.begin())
        {
            it2--;
            int x = *it2;
            ans = min(ans, abs(x - x1) + abs(x - x2) + (abs(y1 - y2) + v - 1) / v);
        }

        printf("%d\n", ans);
    }

    return 0;
}