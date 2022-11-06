#include <cstdio>
#include <iostream>
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

int a[200010];
int t[200010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, l, s, g, x, i;
    scanf("%d%d", &n, &l);
    for(i = 0; i < n; i++)
        scanf("%d%d", &a[i], &t[i]);

    s = 0;
    g = n;
    while(s < g)
    {
        x = (s + g + 1) / 2;

        vector<int> sor;
        for(i = 0; i < n; i++)
            if(a[i] >= x)
                sor.push_back(t[i]);

        if(sor.size() < x)
        {
            g = x - 1;
            continue;
        }

        sort(sor.begin(), sor.end());

        int sum = 0;
        for(i = 0; i < x; i++)
            sum += sor[i];

        if(sum <= l)
            s = x;
        else
            g = x - 1;
    }
    
    x = s;
    vector<pair<int, int>> sor;
    for(i = 0; i < n; i++)
        if(a[i] >= x)
            sor.push_back({ t[i], i + 1 });
    sort(sor.begin(), sor.end());

    printf("%d\n%d\n", x, x);
    for(i = 0; i < x; i++)
        printf("%d ", sor[i].second);
    return 0;
}