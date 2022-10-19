#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 17;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

struct ban
{
    int x, y, b;
    ban()
    {
        x = y = b = 0;
    }
};

int n, m;
char a[N][N];
int aplex, apley;

int d;
int ux[N], uy[N];

bool c[N][N][(1 << 16)];
int dist[N][N][(1 << 16)];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '@')
            {
                aplex = i;
                apley = j;
                a[i][j] = '.';
            }
            else if ('1' <= a[i][j] && a[i][j] <= '9')
            {
                d = max(d, a[i][j] - '0');
                ux[a[i][j] - '0'] = i;
                uy[a[i][j] - '0'] = j;
                a[i][j] = '.';
            }
        }
    }
    ban s;
    s.x = ux[1];
    s.y = uy[1];
    for (int i = 1; i < d; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int hx = ux[i] + xx[j];
            int hy = uy[i] + yy[j];
            if (hx == ux[i + 1] && hy == uy[i + 1])
            {
                s.b |= (j << ((i - 1) * 2));
            }
        }
    }
    queue<ban> q;
    c[s.x][s.y][s.b] = true;
    q.push(s);
    while (!q.empty())
    {
        ban t = q.front();
        q.pop();
        if (t.x == aplex && t.y == apley)
        {
            printf("%d\n", dist[t.x][t.y][t.b]);
            return;
        }
        ux[1] = t.x;
        uy[1] = t.y;
        for (int i = 1; i < d; ++i)
        {
            int j = ((t.b >> ((i - 1) * 2)) & 3);
            ux[i + 1] = ux[i] + xx[j];
            uy[i + 1] = uy[i] + yy[j];
        }
        for (int j = 0; j < 4; ++j)
        {
            ban h;
            h.x = t.x + xx[j];
            h.y = t.y + yy[j];
            if (!(h.x >= 0 && h.x < n && h.y >= 0 && h.y < m))
                continue;
            if (a[h.x][h.y] == '#')
                continue;
            bool z = true;
            for (int i = 1; i < d; ++i)
            {
                if (ux[i] == h.x && uy[i] == h.y)
                {
                    z = false;
                    break;
                }
            }
            if (!z)
                continue;
            h.b = ((t.b << 2) & ((1 << ((d - 1) * 2)) - 1));
            h.b |= ((j + 2) % 4);
            if (!c[h.x][h.y][h.b])
            {
                c[h.x][h.y][h.b] = true;
                dist[h.x][h.y][h.b] = dist[t.x][t.y][t.b] + 1;
                q.push(h);
            }
        }
    }
    printf("-1\n");
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