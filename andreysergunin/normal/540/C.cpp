#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2000;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int a[MAXN][MAXN];
int v[MAXN][MAXN];

void dfs(int x, int y)
{
    v[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a[x + dx[i]][y + dy[i]] == 1)
            v[x + dx[i]][y + dy[i]] = 1;
        if (v[x + dx[i]][y + dy[i]] == 0 && a[x + dx[i]][y + dy[i]] == 0)
            dfs(x + dx[i], y + dy[i]);
    }


}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    string s[MAXN];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            a[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = (s[i - 1][j - 1] == '.' ? 0 : 1);
    int xs, ys, xf, yf;
    cin >> xs >> ys;
    cin >> xf >> yf;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            v[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            v[i][j] = 0;
    a[xs][ys] = 0;
    dfs(xs, ys);
    int t = 0;
    for (int i = 0; i < 4; i++)
        if (a[xf + dx[i]][yf + dy[i]] == 0)
            t++;
    if (xf == xs && ys == yf)
    {
        if (t >= 1)
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }
    if (v[xf][yf] == 0)
    {
        cout << "NO";
        return 0;
    }
    if (a[xf][yf] == 1)
    {
        cout << "YES";
        return 0;
    }
    if (t >= 2)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";

    return 0;
}