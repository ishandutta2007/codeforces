#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
    long n, l, x, y , i, j, a[200000], q1, q2;
    bool fx, fy, fxy1, fxy2;
    cin >> n >> l >> x >> y;
    for (i = 0; i < n; i++)
        cin >> a[i];
    i = 0;
    j = 0;
    fx = false;
    while (j != n - 1 || a[j] - a[i] >= x)
    {
        if (a[j] - a[i] == x)
        {
            fx = true;
            break;
        }
        else
            if (a[j] - a[i] > x)
                i++;
            else
                j++;
    }

    i = 0;
    j = 0;
    fy = false;
    while (j != n - 1 || a[j] - a[i] >= y)
    {
        if (a[j] - a[i] == y)
        {
            fy = true;
            break;
        }
        else
            if (a[j] - a[i] > y)
                i++;
            else
                j++;
    }

    i = 0;
    j = 0;
    fxy1 = false;
    while (j != n - 1 || a[j] - a[i] >= x + y)
    {
        if (a[j] - a[i] == x + y)
        {
            fxy1 = true;
            q1 = a[i];
            break;
        }
        else
            if (a[j] - a[i] > x + y)
                i++;
            else
                j++;
    }

    i = 0;
    j = 0;
    fxy2 = false;
    while (j != n - 1 || a[j] - a[i] >= y - x)
    {
        if (a[j] - a[i] == y - x)
        {
            if (a[i] - x >=0 || a[i] + y <= l)
            {
                fxy2 = true;
                if (a[i] - x >= 0)
                    q2 = a[i] - x;
                else
                    q2 = a[i] + y;
                break;
            }
            i++;
        }
        else
            if (a[j] - a[i] > y - x)
                i++;
            else
                j++;
    }

    if (fx && fy)
        cout << 0;
    else
    {
         if (fx)
         {
             cout << 1 << '\n';
             cout << y;
         }
         else
            if (fy)
            {
                cout << 1 << '\n';
                cout << x;
            }
            else
                if (fxy1)
                {
                    cout << 1 << '\n';
                    cout << q1 + x;
                }
                else
                    if (fxy2)
                    {
                        cout << 1 << '\n';
                        cout << q2;
                    }
                    else
                    {
                        cout << 2 << '\n';
                        cout << x << ' ' << y;
                    }
    }
}