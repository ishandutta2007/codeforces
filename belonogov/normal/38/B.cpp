#include <iostream>
#include <cstdio>

using namespace std;
const int b[8][2] = {{1, 2},{1, -2},{-1, 2},{-1, -2},{2, 1},{-2, -1},{-2, 1},{2, -1}};

int a[8][8];

void hod(int x, int y)
{
    int x1, y1;
    for (int i = 0; i < 8; i++)
    {
        x1 = x + b[i][0];
        y1 = y + b[i][1];
        if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8)
            a[x1][y1]= 1;
    }
}
int main()
{
     string s1, s2;
    int x1, y1, x2, y2, i, j, res = 0;
    cin >> s1;
    cin >> s2;
    x1 = s1[1] - '1';
    x2 = s2[1] - '1';
    y1 = s1[0] - 'a';
    y2 = s2[0] - 'a';
    for (i = 0; i < 8; i++)
        a[y1][i] = 1;
    for (i = 0; i < 8; i++)
        a[i][x1] = 1;
    hod(y1, x1);
    hod(y2, x2);
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if (! a[i][j])
                res++;
    cout << res - 1;
    return 0;
}