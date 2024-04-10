#include <bits/stdc++.h>
using namespace std;

int n;
bool qry(int x1, int x2, int y1, int y2)
{
    //if (x1 == x2 && y1 == y2)
    //    return 1;
    if (x1 == 1 && x2 == n && y1 == 1 && y2 == n)
        return 0;
    if (x2 < x1)
        swap(x1, x2);
    if (y2 < y1)
        swap(y1, y2);
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int k;
    cin >> k;
    if (k == -1)
        exit(0);
    return (k % 2);
}

int x1, x2, y1, y2;

int main()
{
    cin >> n;
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (qry(1, i, 1, n))
        {
            x1 = i;
            int l = 1, r = n;
            while ((r - l + 1) != 1)
            {
                int m = (l + r) / 2;
                if (qry(1, i, 1, m))
                    r = m;
                else
                    l = m + 1;
            }
            y1 = l;
            z = true;
            break;
        }
    }
    if (z)
    {
        for (int i = n; i >= 1; --i)
        {
            if (qry(i, n, 1, n))
            {
                x2 = i;
                int l = 1, r = n;
                while ((r - l + 1) != 1)
                {
                    int m = (l + r) / 2;
                    if (qry(i, n, 1, m))
                        r = m;
                    else
                        l = m + 1;
                }
                y2 = l;
                break;
            }
        }
    }
    else
    {
        for (int j = 1; j <= n; ++j)
        {
            if (qry(1, n, 1, j))
            {
                y1 = j;
                int l = 1, r = n;
                while ((r - l + 1) != 1)
                {
                    int m = (l + r) / 2;
                    if (qry(1, m, 1, j))
                        r = m;
                    else
                        l = m + 1;
                }
                x1 = l;
                break;
            }
        }
        for (int j = n; j >= 1; --j)
        {
            if (qry(1, n, j, n))
            {
                y2 = j;
                int l = 1, r = n;
                while ((r - l + 1) != 1)
                {
                    int m = (l + r) / 2;
                    if (qry(1, m, j, n))
                        r = m;
                    else
                        l = m + 1;
                }
                x2 = l;
                break;
            }
        }
    }
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    return 0;
}