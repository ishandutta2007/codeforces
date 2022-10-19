#include <bits/stdc++.h>
using namespace std;
const int a[6] = {4, 8, 15, 16, 23, 42};

int main()
{
    cout << "? 1 2" << endl;
    int xy;
    cin >> xy;
    int x;
    int y;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (a[i] * a[j] == xy)
            {
                x = a[i];
                y = a[j];
            }
        }
    }
    cout << "? 2 3" << endl;
    int hz;
    cin >> hz;
    int z;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (a[i] * a[j] == hz)
            {
                if (a[i] == x || a[j] == x)
                    swap(x, y);
                if (a[i] == x || a[i] == y)
                    z = a[j];
                else
                    z = a[i];
            }
        }
    }

    cout << "? 4 5" << endl;
    int xy1;
    cin >> xy1;
    int x1;
    int y1;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (a[i] * a[j] == xy1)
            {
                x1 = a[i];
                y1 = a[j];
            }
        }
    }
    cout << "? 5 6" << endl;
    int hz1;
    cin >> hz1;
    int z1;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (a[i] * a[j] == hz1)
            {
                if (a[i] == x1 || a[j] == x1)
                    swap(x1, y1);
                if (a[i] == x1 || a[i] == y1)
                    z1 = a[j];
                else
                    z1 = a[i];
            }
        }
    }
    cout << "! " << x << ' ' << y << ' ' << z << ' ' << x1 << ' ' << y1 << ' ' << z1 << endl;
    return 0;
}