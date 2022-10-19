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
struct ban
{
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator==(const ban& a, const ban& b)
{
    return (a.x == b.x && a.y == b.y);
}

int n, m, d;
char a[N][N];

vector<ban> v;

int c[N][N];
vector<ban> u;
void clr()
{
    for (int i = 0; i < u.size(); ++i)
    {
        c[u[i].x][u[i].y] = 0;
    }
    u.clear();
}
void bfs(int x, int y)
{
    clr();
    queue<ban> q;
    c[x][y] = 1;
    q.push(ban(x, y));
    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        q.pop();
        u.push_back(ban(x, y));
        if (c[x][y] == d + 1)
            continue;
        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (hx >= 1 && hx <= n && hy >= 1 && hy <= m && !c[hx][hy] && a[hx][hy] != 'X')
            {
                c[hx][hy] = c[x][y] + 1;
                q.push(ban(hx, hy));
            }
        }
    }
}

vector<ban> uu[N];

int q[N][N];

void solv()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'R')
                v.push_back(ban(i, j));
        }
    }
    if (sz(v) > 290)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        bfs(v[i].x, v[i].y);
        uu[i] = u;
    }
    for (int i = 0; i < uu[0].size(); ++i)
    {
        int x1 = uu[0][i].x;
        int y1 = uu[0][i].y;
        bfs(x1, y1);
        for (int k = 0; k < u.size(); ++k)
            ++q[u[k].x][u[k].y];
        int ii = -1;
        for (int j = 0; j < v.size(); ++j)
        {
            if (!q[v[j].x][v[j].y])
            {
                ii = j;
                break;
            }
        }
        if (ii == -1)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                {
                    if (a[i][j] != 'X' && m_p(x1, y1) != m_p(i, j))
                    {
                        printf("%d %d %d %d\n", x1, y1, i, j);
                        return;
                    }
                }
            }
            return;
        }
        for (int j = 0; j < uu[ii].size(); ++j)
        {
            int x2 = uu[ii][j].x;
            int y2 = uu[ii][j].y;
            if (m_p(x1, y1) == m_p(x2, y2))
                continue;
            bfs(x2, y2);
            for (int k = 0; k < u.size(); ++k)
                ++q[u[k].x][u[k].y];
            bool z = true;
            for (int k = 0; k < v.size(); ++k)
            {
                if (!q[v[k].x][v[k].y])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                printf("%d %d %d %d\n", x1, y1, x2, y2);
                return;
            }
            bfs(x2, y2);
            for (int k = 0; k < u.size(); ++k)
                --q[u[k].x][u[k].y];
        }
        bfs(x1, y1);
        for (int k = 0; k < u.size(); ++k)
            --q[u[k].x][u[k].y];
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    #ifndef SOMETHING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}