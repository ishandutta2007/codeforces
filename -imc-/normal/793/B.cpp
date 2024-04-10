#include <bits/stdc++.h>

using namespace std;

typedef long long li;

#define all(v) (v).begin(), (v).end()

int n, m;

struct point
{
    int x, y;
    
    point(int x, int y): x(x), y(y) {}
    
    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator*(int t) const { return point(x * t, y * t); }
};

bool inside(point p)
{
    return p.x >= 0 && p.y >= 0 && p.x <= n - 1 && p.y <= m - 1;
}

vector<vector<char>> can[2];

vector<string> g;

void go(point a, point dir1, point dir2, vector<vector<char>>& to, bool only1 = false)
{
    to[a.x][a.y] = true;
    for (int l = 0;; l++)
    {
        a = a + dir1;
        if (!inside(a)) return;
        if (g[a.x][a.y] == '*') return;
        
        to[a.x][a.y] = true;
        
        if (only1) continue;
        
        point b = a;
        for (int l2 = 0;; l2++)
        {
            b = b + dir2;
            if (!inside(b)) break;
            if (g[b.x][b.y] == '*') break;
            
            to[b.x][b.y] = true;
        }
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n);
    
    int si[2] = { -1, -1 }, sj[2] = { -1, -1 };
    
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S')
                si[0] = i, sj[0] = j;
            else if (g[i][j] == 'T')
                si[1] = i, sj[1] = j;
    }
    
    vector<vector<char>> can_e(n, vector<char>(m, false));
    can[0] = can[1] = can_e;
    
    for (int t = -1; t <= 1; t += 2)
    {
        for (int k = 0; k < 2; k++)
        {
            go(point(si[k], sj[k]), point(t, 0), point(0, 1), can[k], k == 1);
            go(point(si[k], sj[k]), point(t, 0), point(0, -1), can[k], k == 1);
            go(point(si[k], sj[k]), point(0, t), point(1, 0), can[k], k == 1);
            go(point(si[k], sj[k]), point(0, t), point(-1, 0), can[k], k == 1);
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (can[0][i][j] && can[1][i][j])
            {
                cout << "YES" << endl;
                return 0;
            }
    
    cout << "NO" << endl;
    return 0;
}