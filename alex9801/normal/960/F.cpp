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
#include <iterator>

using namespace std;

map<int, int> arr[100001];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i;
    scanf("%d%d", &n, &m);

    int ans = 1;
    for(i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        auto it = arr[a].upper_bound(-w);

        int s;
        if(it == arr[a].end())
            s = 1;
        else
            s = 1 + it->second;

        auto it2 = arr[b].lower_bound(-w);
        if(it2 != arr[b].end() && it2->second >= s)
            continue;

        auto it3 = arr[b].insert({ -w, s }).first;
        while(it3 != arr[b].begin())
        {
            if(prev(it3)->second <= s)
                arr[b].erase(prev(it3));
            else
                break;
        }

        ans = max(ans, s);
    }

    printf("%d\n", ans);
    return 0;
}