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
const int N = 1003;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
char a[N][N];

char b[N][N];

void por()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", a[i]);
    }
    int q;
    scanf("%d", &q);
    for (int ii = 1; ii <= q; ++ii)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                b[i][j] = a[i][j];
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + xx[k];
                    int y = j + yy[k];
                    if (x >= 0 && y >= 0 && x < n && y < m)
                    {
                        if (a[i][j] == a[x][y])
                        {
                            b[i][j] = ((a[i][j] - '0') ^ 1) + '0';
                            break;
                        }
                    }
                }
            }
        }
        memcpy(a, b, sizeof b);
        printf("\n\n");
        for (int i = 0; i < n; ++i)
        {
            printf("%s\n", a[i]);
        }
    }
    printf("\n\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%s\n", a[i]);
    }
}

char c[N][N];
int d[N][N];
void bfs()
{
    memset(c, false, sizeof c);
    queue<pair<int, int> > q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int x = i + xx[k];
                int y = j + yy[k];
                if (x >= 0 && y >= 0 && x < n && y < m)
                {
                    if (a[i][j] == a[x][y])
                    {
                        q.push(m_p(i, j));
                        c[i][j] = a[i][j];
                        break;
                    }
                }
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (hx >= 0 && hx < n && hy >= 0 && hy < m)
            {
                if (!c[hx][hy])
                {
                    c[hx][hy] = c[x][y];
                    d[hx][hy] = d[x][y] + 1;
                    q.push(m_p(hx, hy));
                }
            }
        }
    }
}

void solv()
{
    int qq;
    scanf("%d%d%d", &n, &m, &qq);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", a[i]);
    }
    bfs();
    while (qq--)
    {
        int x, y;
        long long p;
        scanf("%d%d%lld", &x, &y, &p);
        --x;
        --y;
        if (!c[x][y])
        {
            printf("%c\n", a[x][y]);
            continue;
        }
        if (p < d[x][y])
            printf("%c\n", a[x][y]);
        else
        {
            char ans = c[x][y];
            if (d[x][y] % 2 == 1)
            {
                if (ans == '0')
                    ans = '1';
                else
                    ans = '0';
            }
            if ((p - d[x][y]) % 2 == 1)
            {
                if (ans == '0')
                    ans = '1';
                else
                    ans = '0';
            }
            printf("%c\n", ans);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //por();
    //return 0;
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}