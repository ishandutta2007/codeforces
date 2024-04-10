#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
int  a[10][10];

int main()
{
    int n, x, y, i, i1, i2, i3;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = a[y][x] = 1;
    }
    for (i1 = 0; i1 < 5; i1++)
        for (i2 = i1 + 1; i2 < 5; i2++)
            for (i3 = i2 + 1; i3 < 5; i3++)
                if (a[i1][i2] == a[i2][i3] && a[i1][i2] == a[i1][i3])
                {
                    cout << "WIN";
                    return 0;
                }

    cout <<  "FAIL";
    return 0;
}