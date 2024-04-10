#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 1000000000;
const int xx[4] = {1, -1, 0, 0};
const int yy[4] = {0, 0, 1, -1};

int n;
int a[N];

int y;

bool stg()
{
    int i = (a[0] - 1) / y + 1;
    int j = (a[0] - 1) % y + 1;
    for (int ii = 0; ii < n - 1; ++ii)
    {
        bool z = false;
        for (int k = 0; k < 4; ++k)
        {
            int hi = i + xx[k];
            int hj = j + yy[k];
            if (hi >= 1 && hi <= M && hj >= 1 && hj <= y && y * (hi - 1) + hj == a[ii + 1])
            {
                z = true;
                i = hi;
                j = hj;
                break;
            }
        }
        if (!z)
            return z;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) != 1)
        {
            if (a[i] == a[i + 1])
            {
                cout << "NO" << endl;
                return 0;
            }
            y = abs(a[i] - a[i + 1]);
            break;
        }
    }
    if (!y)
    {
        for (int i = 0; i < n; ++i)
            y = max(y, a[i]);
        cout << "YES" << endl;
        cout << M << ' ' << y << endl;
        return 0;
    }
    if (stg())
    {
        cout << "YES" << endl;
        cout << M << ' ' << y << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}