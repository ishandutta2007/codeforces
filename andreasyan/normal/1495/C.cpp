#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 502;

int n, m;
char a[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }

    for (int j = 1; j <= m; j += 3)
    {
        for (int i = 1; i <= n; ++i)
            a[i][j] = 'X';
    }

    if (m % 3 == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][m] == 'X')
            {
                a[i][m - 1] = 'X';
            }
        }
    }
    for (int j = 1; j <= m; j += 3)
    {
        if (j + 3 > m)
            break;
        bool z = false;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j + 1] == 'X')
            {
                a[i][j + 2] = 'X';
                z = true;
                break;
            }
        }
        if (z)
            continue;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j + 2] == 'X')
            {
                a[i][j + 1] = 'X';
                z = true;
                break;
            }
        }
        if (z)
            continue;
        a[1][j + 1] = a[1][j + 2] = 'X';
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            putchar(a[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}