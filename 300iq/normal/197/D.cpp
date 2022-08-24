#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

const int N = 1500;
pair <int, int> u[N][N];
char c[N][N];
int n, m;

void dfs(int x, int y)
{
    u[(x % n + n) % n][(y % m + m) % m] = {x, y};
    for (int t = 0; t < 4; t++)
    {
        int gx = ((x % n + n) % n + dx[t] + n) % n;
        int gy = ((y % m + m) % m + dy[t] + m) % m;
        if (c[gx][gy] != '#' && u[gx][gy] != make_pair(x + dx[t], y + dy[t]))
        {
            if (u[gx][gy] != make_pair(INT_MAX, INT_MAX))
            {
                cout << "Yes\n";
                exit(0);
            }
            else
            {
                dfs(x + dx[t], y + dy[t]);
            }
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            u[i][j] = {INT_MAX, INT_MAX};
            cin >> c[i][j];
            if (c[i][j] == 'S')
            {
                x = i, y = j;
            }
        }
    }
    dfs(x, y);
    cout << "No\n";
}