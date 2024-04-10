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

bool chk[300010];
int arr[300010];
int idx[1050000];
int bp;

void add(int x, int v)
{
    x += bp;
    while(x)
    {
        idx[x] += v;
        x /= 2;
    }
}

int sum(int x, int y)
{
    if(y < x)
        return 0;

    int r = 0;
    x += bp;
    y += bp;
    while(x < y)
    {
        if(x % 2 == 1)
            r += idx[x++];
        if(y % 2 == 0)
            r += idx[y--];
        x /= 2;
        y /= 2;
    }
    if(x == y)
        r += idx[x];
    return r;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, s, g, x, l, r, i;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    if(n == 1)
    {
        printf("0");
        return 0;
    }

    sort(arr + 1, arr + n + 1);

    for(bp = 1; bp <= n; bp *= 2);

    chk[0] = 1;
    add(0, 1);

    s = 0;
    g = 1000000000;
    while(s < g)
    {
        x = (s + g) / 2;

        for(i = 1; i <= n; i++)
        {
            if(i < k || arr[i] - arr[i - k + 1] > x)
                continue;

            l = lower_bound(arr + 1, arr + n + 1, arr[i] - x) - arr - 1;
            r = i - k;
            if(sum(l, r))
            {
                chk[i] = 1;
                add(i, 1);
            }
        }

        if(chk[n])
            g = x;
        else
            s = x + 1;

        for(i = 1; i <= n; i++)
        {
            if(chk[i])
            {
                chk[i] = 0;
                add(i, -1);
            }
        }
    }
    printf("%d", s);
    return 0;
}