#include <iostream>

using namespace std;

char a[100][100], b[100][100];
int n, m;

void r(int x, int y, char l)
{
    if(x == -1 or x == n or y == -1 or y == m)
        return;
    if(a[x][y] == '-' or b[x][y] != '-')
        return;
    b[x][y] = l;
    l = l == 'B' ? 'W' : 'B';
    r(x, y - 1, l);
    r(x, y + 1, l);
    r(x - 1, y, l);
    r(x + 1, y, l);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            b[i][j] = '-';
            cin >> a[i][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            r(i, j, 'B');
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << b[i][j];
        cout << endl;
    }
}