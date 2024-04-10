#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long arr[100000];
int x[50];
int y[50];

int main()
{
    bool uu;
    int n, l, a, s, g, m, u, v, c, i;
    long long t;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf("%lld", &arr[i]);

    t = 1;
    l = 0;
    for(i = 0; i<n; i++)
    {
        while(arr[i] >= 2*t)
        {
            t *= 2;
            l++;
        }

        if(arr[i] == t)
            x[l]++;
        else
            y[l]++;
    }

    a = x[0];
    if(a == 0)
    {
        printf("-1");
        return 0;
    }

    for(i = 0; i<=l; i++)
    {
        if(y[i] > x[i])
        {
            printf("-1");
            return 0;
        }
    }

    s = -1;
    g = a/2;
    while(s < g)
    {
        m = (s+g+1)/2;

        u = a - 2*m;
        v = m;

        uu = 1;
        for(i = 1; i<=l; i++)
        {
            if(y[i] > u)
            {
                uu = 0;
                break;
            }

            c = max(0, (x[i]-y[i] - v - (u-y[i])));
            if(c > u-y[i])
            {
                uu = 0;
                break;
            }

            u = min(x[i] - y[i], u - y[i] - c);
            v = x[i] - u - c;
        }

        if(uu)
            s = m;
        else
            g = m-1;
    }

    if(s == -1)
    {
        printf("-1");
        return 0;
    }

    for(i = s; i>=0; i--)
        printf("%d ", a - i);
    return 0;
}