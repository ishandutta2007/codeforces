#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

int n, m, aa, b, c;
char a[N][N];

char u(int i, int j)
{
    return ((i % 5) + (j % 5) * 5) % 26 + 'a';
}

void solv()
{
    scanf("%d%d%d%d%d", &n, &m, &aa, &b, &c);
    if ((n * m) % 2 == 1)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    if (n % 2 == 1)
    {
        if (aa < (m / 2))
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        aa -= (m / 2);
        for (int j = 1; j <= m; j += 2)
            a[n][j] = a[n][j + 1] = u(n, j);
    }
    if (m % 2 == 1)
    {
        if (b < (n / 2))
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        b -= (n / 2);
        for (int i = 1; i <= n; i += 2)
            a[i][m] = a[i + 1][m] = u(i, m);
    }
    for (int i = 1; i <= (n / 2) * 2; i += 2)
    {
        for (int j = 1; j <= (m / 2) * 2; j += 2)
        {
            if (c)
            {
                --c;
                a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = u(i, j);
            }
            else if (aa >= 2)
            {
                aa -= 2;
                a[i][j] = a[i][j + 1] = u(i, j);
                a[i + 1][j] = a[i + 1][j + 1] = u(i + 1, j);
            }
            else if (b >= 2)
            {
                b -= 2;
                a[i][j] = a[i + 1][j] = u(i, j);
                a[i][j + 1] = a[i + 1][j + 1] = u(i, j + 1);
            }
            else
            {
                printf("IMPOSSIBLE\n");
                return;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            putchar(a[i][j]);
        putchar('\n');
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