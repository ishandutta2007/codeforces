#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 13;
const int xx0[8] = {1, 2, -1, -2, 1, -2, -1, 2};
const int yy0[8] = {2, 1, -2, -1, -2, 1, 2, -1};
const int xx1[4] = {0, 1, 0, -1};
const int yy1[4] = {1, 0, -1, 0};
const int xx2[4] = {1, -1, 1, -1};
const int yy2[4] = {1, -1, -1, 1};

int n;
int a[N][N];

bool c[N * N][N][N][3];

struct ban
{
    int u, x, y, p, v;
    int d;
    ban(){}
    ban(int u, int x, int y, int p, int v, int d)
    {
        this->u = u;
        this->x = x;
        this->y = y;
        this->p = p;
        this->v = v;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.d > b.d)
        return true;
    if (a.d < b.d)
        return false;
    return a.p > b.p;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    priority_queue<ban> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 1)
            {
                q.push(ban(1, i, j, 0, 0, 0));
                q.push(ban(1, i, j, 0, 1, 0));
                q.push(ban(1, i, j, 0, 2, 0));
            }
        }
    }
    while (1)
    {
        ban t;
        do
        {
            t = q.top();
            q.pop();
        } while (c[t.u][t.x][t.y][t.v]);
        c[t.u][t.x][t.y][t.v] = true;
        if (t.u == n * n + 1)
        {
            printf("%d %d\n", t.d, t.p);
            return 0;
        }
        if (a[t.x][t.y] == t.u)
            q.push(ban(t.u + 1, t.x, t.y, t.p, t.v, t.d));
        if (t.p < N * N * 3 - 1)
        {
            for (int vv = 0; vv < 3; ++vv)
                q.push(ban(t.u, t.x, t.y, t.p + 1, vv, t.d + 1));
        }
        if (t.v == 0)
        {
            for (int i = 0; i < 8; ++i)
            {
                ban h = t;
                h.x += xx0[i];
                h.y += yy0[i];
                ++h.d;
                if (h.x >= 1 && h.x <= n && h.y >= 1 && h.y <= n)
                    q.push(h);
            }
        }
        else if (t.v == 1)
        {
            for (int i = 0; i < 4; ++i)
            {
                ban h = t;
                ++h.d;
                while (1)
                {
                    h.x += xx1[i];
                    h.y += yy1[i];
                    if (!(h.x >= 1 && h.x <= n && h.y >= 1 && h.y <= n))
                        break;
                    q.push(h);
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                ban h = t;
                ++h.d;
                while (1)
                {
                    h.x += xx2[i];
                    h.y += yy2[i];
                    if (!(h.x >= 1 && h.x <= n && h.y >= 1 && h.y <= n))
                        break;
                    q.push(h);
                }
            }
        }
    }
    return 0;
}