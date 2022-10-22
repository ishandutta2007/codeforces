#include <bits/stdc++.h>

using namespace std;

bool isRow(vector<string>& g, int x, int y, int dx, int dy)
{
    for (int t = 0; t < 5; t++)
    {
        if (!(x >= 0 && y >= 0 && x < 10 && y < 10)) return false;
        if (g[x][y] != 'X') return false;
        
        x += dx;
        y += dy;
    }
    
    return true;
}

bool isWin(vector<string> g)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (isRow(g, i, j, 1, 0) || isRow(g, i, j, 1, 1) || isRow(g, i, j, 0, 1) || isRow(g, i, j, -1, 1))
                return true;
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> g(10);
    for (int i = 0; i < 10; i++)
        cin >> g[i];
    
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            if (g[i][j] != '.') continue;
            g[i][j] = 'X';
            if (isWin(g))
            {
                cout << "YES\n";
                return 0;
            }
            g[i][j] = '.';
        }
        
    cout << "NO\n";
    
    return 0;
}