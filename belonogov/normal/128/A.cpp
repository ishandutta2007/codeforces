#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;
const int hod[9][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                        {1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, 0}};
char a[10][10];
string s;
bool use[10][10][10];
char b[10][10];
bool check = false;
bool p(int x, int y)
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
        return true;
    return false;
}

void dfs(int x, int y, int k)
{
    char b[10][10];
    int  i, j;
    if (check)
        return;
    if (k >= 8 && ! check)
    {
        cout << "WIN";
        check = true;
        return;
    }
    use[x][y][k] = 1;
    //gen(k, &b);
     for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            b[i][j] = '.';
    for (i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            if (a[i][j] == 'S' && (i + k) < 8)
                b[i + k][j] = 'S';
    for (i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            if (a[i][j] == 'S' && (i + k + 1) < 8)
                b[i + k + 1][j] = 'S';
    for (i = 0; i < 9; i++)
    {
        if ((p(x + hod[i][0], y + hod[i][1])) && (b[x + hod[i][0]][y + hod[i][1]] != 'S') &&
            (use[x + hod[i][0]][y + hod[i][1]][k + 1] == 0))

        dfs(x + hod[i][0], y + hod[i][1], k + 1);
    }

}


int main()
{
     int i, j;

    for (i = 0; i < 8; i++)
    {
        cin >> s;
        for (j = 0; j < 8; j++)
            a[i][j] = s[j];
    }
    dfs(7, 0, 0);
    if (! check)
    {
        cout << "LOSE";
    }
    return 0;
}