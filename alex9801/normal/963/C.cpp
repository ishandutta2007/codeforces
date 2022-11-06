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

struct str
{
    long long x, y, c;
    bool operator <(const str &a) const
    {
        return make_pair(x, y) < make_pair(a.x, a.y);
    }
};

str arr[200010];

long long gcd(long long x, long long y)
{
    return x ? gcd(y % x, x) : y;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%lld%lld%lld", &arr[i].x, &arr[i].y, &arr[i].c);
    
    sort(arr, arr + n);

    int w, h;
    for(i = 0; i < n; i++)
    {
        if(i == n - 1 || arr[i].x != arr[i + 1].x)
        {
            w = i + 1;
            break;
        }
    }

    if(n % w != 0)
    {
        printf("0\n");
        return 0;
    }

    h = n / w;

    for(i = 1; i < h; i++)
    {
        int s = w * i;
        long long x = arr[s].x;

        long long p0 = arr[s].c;
        long long q0 = arr[0].c;
        
        long long g0 = gcd(p0, q0);
        p0 /= g0;
        q0 /= g0;

        for(j = s; j < s + w; j++)
        {
            if(arr[j].x != x || arr[j].y != arr[j - s].y)
            {
                printf("0\n");
                return 0;
            }

            long long p = arr[j].c;
            long long q = arr[j - s].c;

            long long g = gcd(p, q);
            p /= g;
            q /= g;

            if(p != p0 || q != q0)
            {
                printf("0\n");
                return 0;
            }
        }
    }

    long long s = arr[0].c;
    for(i = 1; i < n; i++)
        s = gcd(s, arr[i].c);

    long long res = 0;
    for(long long d = 1; d*d <= s; d++)
    {
        if(s % d == 0)
        {
            if(d * d == s)
                res++;
            else
                res += 2;
        }
    }
    printf("%lld\n", res);

    return 0;
}