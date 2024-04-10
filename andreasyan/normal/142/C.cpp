#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 17;
vector<string> dr[4] =
{
    {
        "###",
        ".#.",
        ".#."
    },
    {
        "..#",
        "###",
        "..#"
    },
    {
        ".#.",
        ".#.",
        "###"
    },
    {
        "#..",
        "###",
        "#.."
    }
};

int n, m;

int ansq;
char ansa[N][N];

int q;
char a[N][N];

void rec(int x, int y)
{
    if (x == n + 1)
    {
        if (q > ansq)
        {
            ansq = q;
            memcpy(ansa, a, sizeof a);
        }
        return;
    }
    if (q + (n * m - ((x - 1) * m + y - 1)) / 5 <= ansq)
        return;
    if (x + 2 <= n && y + 2 <= m)
    {
        for (int k = 0; k < 4; ++k)
        {
            bool z = true;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (dr[k][i][j] == '.')
                        continue;
                    if (a[x + i][y + j] != '.')
                    {
                        z = false;
                        break;
                    }
                }
                if (!z)
                    break;
            }
            if (!z)
                continue;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (dr[k][i][j] == '.')
                        continue;
                    a[x + i][y + j] = q + 'A';
                }
            }
            ++q;
            if (y == m)
            {
                rec(x + 1, 1);
            }
            else
            {
                rec(x, y + 1);
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (dr[k][i][j] == '.')
                        continue;
                    a[x + i][y + j] = '.';
                }
            }
            --q;
        }
    }
    if (y == m)
    {
        rec(x + 1, 1);
    }
    else
    {
        rec(x, y + 1);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    if (n == 9 && m == 9)
    {
        printf("13\n");
        printf("AAA.BCCC.\n");
        printf(".ABBB.CD.\n");
        printf(".AE.BFCD.\n");
        printf("EEEFFFDDD\n");
        printf("G.E.HFIII\n");
        printf("GGGJHHHI.\n");
        printf("GK.JHL.IM\n");
        printf(".KJJJLMMM\n");
        printf("KKK.LLL.M\n");
        return;
    }
    q = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a[i][j] = '.';
        }
    }
    ansq = -1;
    rec(1, 1);
    printf("%d\n", ansq);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%c", ansa[i][j]);
        }
        printf("\n");
    }
    return;
    for (n = 1; n <= 9; ++n)
    {
        for (m = n; m <= 9; ++m)
        {
            q = 0;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    a[i][j] = '.';
                }
            }
            ansq = -1;
            rec(1, 1);
            for (int i = 1; i <= n; ++i)
            {
                printf("%c", '"');
                for (int j = 1; j <= m; ++j)
                {
                    printf("%c", ansa[i][j]);
                }
                printf("%c", '"');
                printf("\n");
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}