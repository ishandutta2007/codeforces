#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100010];
int cnt[100010];
int a, b, h, w, n;
int INF = 100010;
vector<int> tmp;

int v(int a, int b)
{
    return 1LL*a*b > INF ? INF : a*b;
}

int pp(int a, int x)
{
    if(x == 0)
        return 1;
    if(x%2)
        return v(pp(a, x-1), a);
    int t = pp(a, x/2);
    return v(t, t);
}

int hh, ww;

bool g(int x)
{
    if(x == 0)
    {
        hh = h;
        ww = w;
    }

    if(hh >= a && ww >= b)
        return 1;

    if(x == tmp.size())
        return 0;

    int t;
    bool u;
    if(hh < a)
    {
        t = hh;
        hh = v(hh, tmp[x]);
        u = g(x+1);
        hh = t;
        if(u)
            return 1;
    }

    if(ww < b)
    {
        t = ww;
        ww = v(ww, tmp[x]);
        u = g(x+1);
        ww = t;
        if(u)
            return 1;
    }
    return 0;
}

bool f(int x)
{
    int t, i;
    for(i = n-x; i<n; i++)
        cnt[arr[i]]++;

    tmp.clear();
    for(i = n-x; i<n; i++)
    {
        if(!cnt[arr[i]])
            continue;

        t = 1;
        while(t <= cnt[arr[i]])
        {
            tmp.push_back(pp(arr[i], t));
            cnt[arr[i]] -= t;
            t *= 2;
        }
        if(cnt[arr[i]])
        {
            tmp.push_back(pp(arr[i], cnt[arr[i]]));
            cnt[arr[i]] = 0;
        }
    }

    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());

    if(tmp.size() > 16)
        tmp.resize(16);

    if(g(0))
        return 1;

    t = a;
    a = b;
    b = t;
    bool u = g(0);
    t = a;
    a = b;
    b = t;
    return u;
}

int main()
{
    int s, g, x, t, i;
    scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
    for(i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    if(h>=a && w>=b || h>=b && w>=a)
    {
        printf("0");
        return 0;
    }

    sort(arr, arr+n);

    t = min(n, 34);

    s = 1;
    g = t + 1;
    while(s < g)
    {
        x = (s + g)/2;
        if(x == t+1 || f(x))
            g = x;
        else
            s = x+1;
    }

    if(s == t + 1)
        printf("-1");
    else
        printf("%d", s);
    return 0;
}