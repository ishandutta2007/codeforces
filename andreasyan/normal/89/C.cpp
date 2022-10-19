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
const int N = 5003;

int n, m;
char** a;

int** l;
int** r;
int** u;
int** d;

void bil(char**& a)
{
    a = new char*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new char[m + 5];
    for (int i = 0; i < n + 5; ++i)
        for (int j = 0; j < m + 5; ++j)
            a[i][j] = 0;
}

void bil(int**& a)
{
    a = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new int[m + 5];
    for (int i = 0; i < n + 5; ++i)
        for (int j = 0; j < m + 5; ++j)
            a[i][j] = 0;
}

void han(int x, int y)
{
    r[x][l[x][y]] = r[x][y];
    l[x][r[x][y]] = l[x][y];
    d[u[x][y]][y] = d[x][y];
    u[d[x][y]][y] = u[x][y];
}

int ans;
void go(int x, int y)
{
    if (!(1 <= x && x <= n && 1 <= y && y <= m))
        return;
    ++ans;
    han(x, y);
    if (a[x][y] == 'L')
    {
        go(x, l[x][y]);
    }
    else if (a[x][y] == 'R')
    {
        go(x, r[x][y]);
    }
    else if (a[x][y] == 'U')
    {
        go(u[x][y], y);
    }
    else if (a[x][y] == 'D')
    {
        go(d[x][y], y);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    bil(a);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }
    for (int i = 0; i <= n + 1; ++i)
    {
        a[i][0] = a[i][m + 1] = '.';
    }
    for (int j = 0; j <= m + 1; ++j)
    {
        a[0][j] = a[n + 1][j] = '.';
    }
    bil(l);
    bil(r);
    bil(u);
    bil(d);
    int yans = 0;
    int qans = 0;
    for (int sx = 1; sx <= n; ++sx)
    {
        for (int sy = 1; sy <= m; ++sy)
        {
            if (a[sx][sy] == '.')
                continue;
            for (int i = 1; i <= n; ++i)
            {
                int k = 0;
                for (int j = 1; j <= m; ++j)
                {
                    l[i][j] = k;
                    if (a[i][j] != '.')
                        k = j;
                }
                k = m + 1;
                for (int j = m; j >= 1; --j)
                {
                    r[i][j] = k;
                    if (a[i][j] != '.')
                        k = j;
                }
            }
            for (int j = 1; j <= m; ++j)
            {
                int k = 0;
                for (int i = 1; i <= n; ++i)
                {
                    u[i][j] = k;
                    if (a[i][j] != '.')
                        k = i;
                }
                k = n + 1;
                for (int i = n; i >= 1; --i)
                {
                    d[i][j] = k;
                    if (a[i][j] != '.')
                        k = i;
                }
            }
            ans = 0;
            go(sx, sy);
            if (ans > yans)
            {
                yans = ans;
                qans = 1;
            }
            else if (ans == yans)
            {
                ++qans;
            }
        }
    }
    printf("%d %d\n", yans, qans);
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