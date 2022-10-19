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
const int N = 1003, M = 100005;

int n, m;
int a[N][N];
char s[M];

int b[N][N], c[N][N];
void solv0()
{
    for (int k = 1; k <= m; ++k)
    {
        if (s[k] == 'R')
        {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    c[i][j] = b[i][(j - 2 + n * 2) % n + 1];
        }
        else if (s[k] == 'L')
        {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    c[i][j] = b[i][j % n + 1];
        }
        else if (s[k] == 'D')
        {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    c[i][j] = b[(i - 2 + n * 2) % n + 1][j];
        }
        else if (s[k] == 'U')
        {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    c[i][j] = b[i % n + 1][j];
        }
        else if (s[k] == 'I')
        {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    c[i][b[i][j]] = j;
        }
        else if (s[k] == 'C')
        {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    c[b[i][j]][j] = i;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                b[i][j] = c[i][j];
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    scanf(" %s", (s + 1));

    int q[3] = {};
    int u[3] = {0, 1, 2};
    for (int i = 1; i <= m; ++i)
    {
        if (s[i] == 'R')
        {
            q[u[1]]++;
        }
        else if (s[i] == 'L')
        {
            q[u[1]]--;
        }
        else if (s[i] == 'D')
        {
            q[u[0]]++;
        }
        else if (s[i] == 'U')
        {
            q[u[0]]--;
        }
        else if (s[i] == 'C')
        {
            swap(u[0], u[2]);
        }
        else
        {
            swap(u[1], u[2]);
        }
    }

    for (int i0 = 1; i0 <= n; ++i0)
    {
        for (int j0 = 1; j0 <= n; ++j0)
        {
            int x[3] = {i0 - 1, j0 - 1, a[i0][j0] - 1};

            for (int i = 0; i < 3; ++i)
            {
                x[i] = (x[i] + q[i] + n * m) % n;
            }

            b[x[u[0]] + 1][x[u[1]] + 1] = x[u[2]] + 1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    printf("\n");
    return;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            b[i][j] = a[i][j];
    solv0();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    printf("\n");
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