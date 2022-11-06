#include <bits/stdc++.h>
using namespace std;

const int THR = 1000000;

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int m, a, b;
bool chk[THR + 1];

int fin;
int f(int x)
{
    int r = 1;
    chk[x] = 1;
    if(x + a <= fin && !chk[x + a])
        r += f(x + a);
    if(x - b >= 0 && !chk[x - b])
        r += f(x - b);
    return r;
}

void f2(int x)
{
    chk[x] = 0;
    if(x + a <= fin && chk[x + a])
        f2(x + a);
    if(x - b >= 0 && chk[x - b])
        f2(x - b);
}

int solve(int x)
{
    fin = x;
    int r = f(0);
    f2(0);
    return r;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d%d%d", &m, &a, &b);

    if(m < a)
    {
        printf("%d\n", m + 1);
        return 0;
    }

    int gab = gcd(a, b);

    int s = gab;
    int g = min(m, THR);
    int pm;
    while(s <= g)
    {
        int x = (s + g) / 2;
        int t = solve(x);

        if(s == g)
        {
            if(t != x / gab + 1)
            {
                assert(s == m);
                pm = s + 1;
            }
            else
            {
                assert(s % g == 0);
                pm = s;
            }

            break;
        }

        if(t == x / gab + 1)
            g = x;
        else
            s = x + 1;
    }

    long long r = 0;

    int p = 0;
    int v = 1;
    while(p < pm)
    {
        int s = p;
        int g = pm - 1;
        while(s < g)
        {
            int x = (s + g + 1) / 2;
            int t = solve(x);
            
            if(t == v)
                s = x;
            else
                g = x - 1;
        }

        r += 1LL * (s - p + 1) * v;

        if(p == pm - 1)
            break;

        p = s + 1;
        v = solve(p);
    }

    if(pm <= m)
    {
        for(int i = 0; i < gab; i++)
        {
            if(i > m)
                continue;

            int s = 0;
            int g = m / gab;
            while(s < g)
            {
                int x = (s + g) / 2;
                if(x * gab + i < pm)
                    s = x + 1;
                else
                    g = x;
            }

            int ll = s + 1;

            s = 0;
            g = m / gab;
            while(s < g)
            {
                int x = (s + g + 1) / 2;
                if(x * gab + i > m)
                    g = x - 1;
                else
                    s = x;
            }

            int rr = s + 1;

            if(ll <= rr)
                r += 1LL * rr * (rr + 1) / 2 - 1LL * (ll - 1) * ll / 2;
        }

        //r += (1LL * (m / gab + 1) * (m / gab + 2) / 2 - 1LL * (pm / gab) * (pm / gab + 1) / 2) * gab;
        //r -= 1LL * (m / gab + 1) * (gab - m % gab - 1);
    }

    printf("%lld\n", r);
    return 0;
}