#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n, r;
char a[N];

void solv()
{
    scanf("%d%d", &n, &r);
    if (r == 1)
    {
        if (n == 1)
        {
            printf("0\n");
            printf("T\n");
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
        return;
    }
    int ans = N;
    for (int i = 1; i < r; ++i)
    {
        int x = i;
        int y = r;
        int q = 0;
        int s = 0;
        while (1)
        {
            if (x == 0 || y == 0)
            {
                break;
            }
            if (y > x)
            {
                s += (y / x) - 1;
                if (x == 1)
                    --s;
                q += (y / x);
                y %= x;
            }
            else
            {
                s += (x / y) - 1;
                if (y == 1)
                    --s;
                q += (x / y);
                x %= y;
            }
        }
        if (x == 0)
        {
            if (y == 1 && n == q)
            {
                ans = min(ans, s);
            }
        }
        else
        {
            if (x == 1 && n == q)
            {
                ans = min(ans, s);
            }
        }
    }
    if (ans == N)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("%d\n", ans);
    for (int i = 1; i < r; ++i)
    {
        int x = i;
        int y = r;
        int q = 0;
        int s = 0;
        while (1)
        {
            if (x == 0 || y == 0)
            {
                break;
            }
            if (y > x)
            {
                s += (y / x) - 1;
                if (x == 1)
                    --s;
                q += (y / x);
                y %= x;
            }
            else
            {
                s += (x / y) - 1;
                if (y == 1)
                    --s;
                q += (x / y);
                x %= y;
            }
        }
        if (x == 0)
        {
            if (y == 1 && n == q)
            {
                if (s == ans)
                {
                    int y = r;
                    int x = i;
                    int m = n;
                    while (1)
                    {
                        if (x == 0 || y == 0)
                            break;
                        if (y > x)
                        {
                            a[--m] = 'T';
                            y -= x;
                        }
                        else
                        {
                            a[--m] = 'B';
                            x -= y;
                        }
                    }
                    if (a[0] == 'B')
                        a[0] = 'T';
                    if (a[1] == 'T')
                    {
                        for (int i = 1; i < n; ++i)
                        {
                            if (a[i] == 'T')
                                a[i] = 'B';
                            else
                                a[i] = 'T';
                        }
                    }
                    printf("%s\n", a);
                    return;
                }
            }
        }
        else
        {
            if (x == 1 && n == q)
            {
                if (s == ans)
                {
                    int y = r;
                    int x = i;
                    int m = n;
                    while (1)
                    {
                        if (x == 0 || y == 0)
                            break;
                        if (y > x)
                        {
                            a[--m] = 'T';
                            y -= x;
                        }
                        else
                        {
                            a[--m] = 'B';
                            x -= y;
                        }
                    }
                    if (a[0] == 'B')
                        a[0] = 'T';
                    if (a[1] == 'T')
                    {
                        for (int i = 1; i < n; ++i)
                        {
                            if (a[i] == 'T')
                                a[i] = 'B';
                            else
                                a[i] = 'T';
                        }
                    }
                    printf("%s\n", a);
                    return;
                }
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}