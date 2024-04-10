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

pair<int, int> a[100010], b[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int k, x;
        scanf("%d%d", &k, &x);
        a[i] = { k, x };
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        int k, x;
        scanf("%d%d", &k, &x);
        b[i] = { k, x };
    }

    sort(a, a + n);
    sort(b, b + m);

    int p = 0, q = 0;
    long long r = 0;

    while(p < n || q < m)
    {
        if(p < n && q < m && a[p].first == b[q].first)
        {
            r += max(a[p].second, b[q].second);
            p++;
            q++;
        }
        else if(q == m || p != n && a[p].first < b[q].first)
        {
            r += a[p].second;
            p++;
        }
        else
        {
            r += b[q].second;
            q++;
        }
    }
    printf("%lld", r);
    return 0;
}