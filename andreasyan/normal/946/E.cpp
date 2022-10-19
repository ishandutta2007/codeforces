#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
char a[N];

int p[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i)
        a[i] -= '0';
    p[0] = (1 << a[0]);
    for (int i = 1; i < n; ++i)
    {
        p[i] = (p[i - 1] ^ (1 << a[i]));
    }
    for (int i = n - 1; i >= 0; --i)
    {
        int s;
        if (i == 0)
            s = 1;
        else
            s = 0;
        for (int j = a[i] - 1; j >= s; --j)
        {
            int x;
            if (!i)
                x = 0;
            else
                x = p[i - 1];
            x ^= (1 << j);
            int q = 0;
            for (int k = 0; k < 10; ++k)
            {
                if ((x & (1 << k)))
                    ++q;
            }
            if (q <= (n - 1 - i) && (n - 1 - i - q) % 2 == 0)
            {
                for (int k = 0; k < i; ++k)
                    putchar(a[k] + '0');
                putchar(j + '0');
                for (int k = 0; k < (n - 1 - i - q); ++k)
                    putchar('9');
                for (int k = 9; k >= 0; --k)
                {
                    if ((x & (1 << k)))
                    {
                        putchar(k + '0');
                    }
                }
                putchar('\n');
                return;
            }
        }
    }
    if (n % 2 == 0)
    {
        for (int i = 0; i < n - 2; ++i)
            putchar('9');
        putchar('\n');
    }
    else
    {
        for (int i = 0; i < n - 1; ++i)
            putchar('9');
        putchar('\n');
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}