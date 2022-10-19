#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2003;
const int xx[4] = {1, -1, 0, 0};
const int yy[4] = {0, 0, 1, -1};
struct ban
{
    int x, y;
    int dl, dr;
    ban(){}
    ban(int x, int y, int dl, int dr)
    {
        this->x = x;
        this->y = y;
        this->dl = dl;
        this->dr = dr;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.dl + a.dr > b.dl + b.dr;
}

int n, m;
int sx, sy;
int ql, qr;
char a[N][N];

bool c[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> qr >> ql;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    --sx;
    --sy;
    int ans = 0;
    priority_queue<ban> q;
    q.push(ban(sx, sy, 0, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
            {
                cout << ans << endl;
                return 0;
            }
            t = q.top();
            q.pop();
        } while (c[t.x][t.y]);
        if (t.dl > ql || t.dr > qr)
        {
            continue;
        }
        c[t.x][t.y] = true;
        ++ans;
        for (int i = 0; i < 4; ++i)
        {
            ban h = t;
            h.x += xx[i];
            h.y += yy[i];
            if (i == 2)
                h.dl++;
            if (i == 3)
                h.dr++;
            if (h.x >= 0 && h.x < n && h.y >= 0 && h.y < m && a[h.x][h.y] == '.')
                q.push(h);
        }
    }
    return 0;
}