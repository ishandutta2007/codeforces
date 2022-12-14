#include <iostream>
#include <stdlib.h>

using namespace std;

char a[52][52];
int used[52][52];

void dfs(char c, int x, int y, int from)
{
    if(used[x][y] == 2 or a[x][y] != c)
        return;
    if(used[x][y] == 1)
    {
        cout << "Yes" << endl;
        exit(0);
    }
    used[x][y] = 1;
    //from: 0up1r2d3l
    if(from != 0)
        dfs(c, x - 1, y, 2);
    if(from != 2)
        dfs(c, x + 1, y, 0);
    if(from != 3)
        dfs(c, x, y - 1, 1);
    if(from != 1)
        dfs(c, x, y + 1, 3);
    used[x][y] = 2;
}


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 0; i <= n + 1; ++i)
        used[i][0] = used[i][m + 1] = 2;
    for(int i = 0; i <= m + 1; ++i)
        used[0][i] = used[n + 1][i] = 2;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(used[i][j] == 0)
                dfs(a[i][j], i, j, -1);
    cout << "No" << endl;
    return 0;
}