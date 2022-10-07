#include <iostream>
#include <cstdio>

using namespace std;
int a[1000];

int main()
{
    int n, m, x, y, i, j;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        for (j = x; j <= y; j++)
            a[j]++;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] != 1)
        {
            cout << i + 1 << " " <<a[i];
            return 0;
        }
    }
    cout << "OK";

    return 0;
}