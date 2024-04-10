#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    if ((m % 2 == 0 && n > 1) || (m == 2))
    {
        cout << 0 << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << ' ' << 1 << endl;
        for (int j = 2; j <= m; ++j)
        {
            if (j % 2 == 0)
            {
                for (int i = n; i >= 2; --i)
                    cout << i << ' ' << j << endl;
            }
            else
            {
                for (int i = 2; i <= n; ++i)
                    cout << i << ' ' << j << endl;
            }
        }
        for (int j = m; j >= 1; --j)
        {
             cout << 1 << ' ' << j << endl;
        }
    }
    else if ((n % 2 == 0 && m > 1) || (n == 2))
    {
        cout << 0 << endl;
        for (int j = 1; j <= m; ++j)
            cout << 1 << ' ' << j << endl;
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                for (int j = m; j >= 2; --j)
                    cout << i << ' ' << j << endl;
            }
            else
            {
                for (int j = 2; j <= m; ++j)
                    cout << i << ' ' << j << endl;
            }
        }
        for (int i = n; i >= 1; --i)
            cout << i << ' ' << 1 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << n << ' ' << m << ' ' << 1 << ' ' << 1 << endl;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 1)
            {
                for (int j = 1; j <= m; ++j)
                    cout << i << ' ' << j << endl;
            }
            else
            {
                for (int j = m; j >= 1; --j)
                    cout << i << ' ' << j << endl;
            }
        }
        cout << "1 1" << endl;
    }
    return 0;
}