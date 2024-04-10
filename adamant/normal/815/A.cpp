#include <bits/stdc++.h>

using namespace std;

int n, m;
int g[101][101];
int cur;

pair<vector<int>, vector<int>> make_try(int cl)
{
    vector<int> col(m), row(n);
    cur = 0;
    for(int i = 0; i < n; i++)
        row[i] = g[i][0] - cl;
    for(int i = 1; i < m; i++)
        col[i] = g[0][i] - row[0];
    col[0] = cl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(row[i] + col[j] != g[i][j])
                row[0] = -1;
    for(auto it: col)
        cur += it;
    for(auto it: row)
        cur += it;
    return {row, col};
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    int mn = 1e9;
    vector<int> row, col;
    for(int col0 = 0; col0 <= 500; col0++)
    {
        auto it = make_try(col0);
        for(auto jt: it.first)
            if(jt < 0)
                goto nxt;
        for(auto jt: it.second)
            if(jt < 0)
                goto nxt;
        if(cur < mn)
        {
            mn = cur;
            row = it.first;
            col = it.second;
        }
        nxt:;
    }
    if(mn == 1e9)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << mn << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < row[i]; j++)
            cout << "row " << i + 1 << "\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < col[i]; j++)
            cout << "col " << i + 1 << "\n";
}
/*
row[i] + col[j] = g[i][j]

*/