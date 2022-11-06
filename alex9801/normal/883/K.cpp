#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int s[200010];
int g[200010];
int l[200010];
int r[200010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long res;
    int n, mn, mx, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d", &s[i], &g[i]);

    for(i = 0; i < n; i++)
    {
        l[i] = s[i];
        r[i] = s[i] + g[i];
    }

    mn = l[0];
    mx = r[0];
    for(i = 1; i < n; i++)
    {
        mn--;
        mx++;

        mn = l[i] = max(l[i], mn);
        mx = r[i] = min(r[i], mx);
    }

    mn = l[n-1];
    mx = r[n-1];
    for(i = n - 2; i >= 0; i--)
    {
        mn--;
        mx++;

        mn = l[i] = max(l[i], mn);
        mx = r[i] = min(r[i], mx);
    }

    for(i = 0; i < n; i++)
    {
        if(r[i] < l[i])
        {
            printf("-1");
            return 0;
        }
    }

    res = 0;
    for(i = 0; i < n; i++)
        res += r[i] - s[i];

    printf("%lld\n", res);
    for(i = 0; i < n; i++)
        printf("%d ", r[i]);

    return 0;
}