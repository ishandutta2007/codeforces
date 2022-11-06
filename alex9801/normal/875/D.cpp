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

int arr[200010];
int idxm[525000];
int idxp[525000];
int idxo[525000];
int bp;

pair<int, int> mv(int x, int y)
{
    int r = -1, p;
    x += bp;
    y += bp;
    while(x < y)
    {
        if(x % 2 == 1)
        {
            if(idxm[x] > r)
            {
                r = idxm[x];
                p = idxp[x];
            }
            x++;
        }
        if(y % 2 == 0)
        {
            if(idxm[y] > r)
            {
                r = idxm[y];
                p = idxp[y];
            }
            y--;
        }
        x /= 2;
        y /= 2;
    }
    if(x == y)
    {
        if(idxm[x] > r)
        {
            r = idxm[x];
            p = idxp[x];
        }
    }
    return { r, p };
}

int ov(int x, int y)
{
    int r = 0;
    x += bp;
    y += bp;
    while(x < y)
    {
        if(x % 2 == 1)
            r |= idxo[x++];
        if(y % 2 == 0)
            r |= idxo[y--];
        x /= 2;
        y /= 2;
    }
    if(x == y)
        r |= idxo[x];
    return r;
}

long long f(int x, int y)
{
    if(y <= x)
        return 0;

    long long res = 0;
    int m, p, s, g, c, p1, p2;

    tie(m, p) = mv(x, y);

    if(ov(x, p) > m)
    {
        s = x;
        g = p;
        while(s < g)
        {
            c = (s + g + 1) / 2;
            if(ov(c, p) > m)
                s = c;
            else
                g = c - 1;
        }
        p1 = s;
    }
    else
        p1 = p;

    if(ov(p, y) > m)
    {
        s = p;
        g = y;
        while(s < g)
        {
            c = (s + g) / 2;
            if(ov(p, c) > m)
                g = c;
            else
                s = c + 1;
        }
        p2 = s;
    }
    else
        p2 = p;

    if(p1 < p && p2 > p)
        res += 1LL * (p - x + 1) * (y - p + 1) - 1LL * (p - p1) * (p2 - p);
    else if(p1 < p && p2 == p)
        res += 1LL * (p1 - x + 1) * (y - p + 1);
    else if(p1 == p && p2 > p)
        res += 1LL * (p - x + 1) * (y - p2 + 1);

    res += f(x, p - 1);
    res += f(p + 1, y);
    return res;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(bp = 1; bp <= n; bp *= 2);

    for(i = 0; i < n; i++)
    {
        idxm[i + bp] = idxo[i + bp] = arr[i];
        idxp[i + bp] = i;
    }
    for(i = bp - 1; i >= 1; i--)
    {
        idxm[i] = max(idxm[2 * i], idxm[2 * i + 1]);
        if(idxm[2 * i] >= idxm[2 * i + 1])
            idxp[i] = idxp[2 * i];
        else
            idxp[i] = idxp[2 * i + 1];
        idxo[i] = idxo[2 * i] | idxo[2 * i + 1];
    }

    printf("%lld", f(0, n - 1));
    return 0;
}