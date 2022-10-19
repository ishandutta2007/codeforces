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

int ka()
{
    int x = 0;
    while (1)
    {
        char y = getchar();
        if ('0' <= y && y <= '9')
            x = (x * 10) + (y - '0');
        else
            return x;
    }
}

struct ban
{
    short x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int n, m;
int s[N][N];

ban u[N][N][4];

ban ans[N];

ban u1[N], u2[N], d1[N], d2[N], l1[N], l2[N], r1[N], r2[N];

void swpp(ban& t1, ban& t2)
{
    t1.x ^= t2.x;
    t2.x ^= t1.x;
    t1.x ^= t2.x;
    t1.y ^= t2.y;
    t2.y ^= t1.y;
    t1.y ^= t2.y;
}

void swp(ban t1, ban t2, int z)
{
    swpp(u[u[t1.x][t1.y][z].x][u[t1.x][t1.y][z].y][(z + 2) % 4],
         u[u[t2.x][t2.y][z].x][u[t2.x][t2.y][z].y][(z + 2) % 4]);
    swpp(u[t1.x][t1.y][z], u[t2.x][t2.y][z]);
}

void tp()
{
    for (int i = 1; i <= n; ++i)
    {
        ban t = ban(i, 0);
        for (int j = 1; j <= m; ++j)
        {
            t = u[t.x][t.y][0];
            printf("%d ", s[t.x][t.y]);
        }
        printf("\n");
    }
}

void solv()
{
    int qq;
    n = ka();
    m = ka();
    qq = ka();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            s[i][j] = ka();
        }
    }
    for (int x = 0; x <= n + 1; ++x)
    {
        for (int y = 0; y <= m + 1; ++y)
        {
            for (int i = 0; i < 4; ++i)
            {
                u[x][y][i] = ban(x + xx[i], y + yy[i]);
            }
        }
    }
    while (qq--)
    {
        int x1 = ka(), y1_ = ka(), x2 = ka(), y2 = ka(), h = ka(), w = ka();

        u1[0] = ban(x1, 0);
        u2[0] = ban(x2, 0);
        for (int j = 1; j <= max(y1_, y2) + w - 1; ++j)
        {
            u1[j] = u[u1[j - 1].x][u1[j - 1].y][0];
            u2[j] = u[u2[j - 1].x][u2[j - 1].y][0];
        }

        d1[0] = ban(x1 + h - 1, 0);
        d2[0] = ban(x2 + h - 1, 0);
        for (int j = 1; j <= max(y1_, y2) + w - 1; ++j)
        {
            d1[j] = u[d1[j - 1].x][d1[j - 1].y][0];
            d2[j] = u[d2[j - 1].x][d2[j - 1].y][0];
        }

        l1[0] = ban(0, y1_);
        l2[0] = ban(0, y2);
        for (int i = 1; i <= max(x1, x2) + h - 1; ++i)
        {
            l1[i] = u[l1[i - 1].x][l1[i - 1].y][1];
            l2[i] = u[l2[i - 1].x][l2[i - 1].y][1];
        }

        r1[0] = ban(0, y1_ + w - 1);
        r2[0] = ban(0, y2 + w - 1);
        for (int i = 1; i <= max(x1, x2) + h - 1; ++i)
        {
            r1[i] = u[r1[i - 1].x][r1[i - 1].y][1];
            r2[i] = u[r2[i - 1].x][r2[i - 1].y][1];
        }

        // R D L U
        for (int j1 = y1_, j2 = y2; j1 <= y1_ + w - 1; ++j1, ++j2)
        {
            swp(u1[j1], u2[j2], 3);
        }

        // R D L U
        for (int j1 = y1_, j2 = y2; j1 <= y1_ + w - 1; ++j1, ++j2)
        {
            swp(d1[j1], d2[j2], 1);
        }

        // R D L U
        for (int i1 = x1, i2 = x2; i1 <= x1 + h - 1; ++i1, ++i2)
        {
            swp(l1[i1], l2[i2], 2);
        }

        // R D L U
        for (int i1 = x1, i2 = x2; i1 <= x1 + h - 1; ++i1, ++i2)
        {
            swp(r1[i1], r2[i2], 0);
        }
    }
    tp();
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}