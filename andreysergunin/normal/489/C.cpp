#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, s, t, i, a[1000];
    cin >> m >> s;
    if (m == 1 && s == 0)
        cout << "0 0\n";
    else
    {
        if (m * 9 < s || s == 0)
            cout << "-1 -1\n";
        else
        {
            t = s;

            for (i = 0; i < m; i++)
                a[i] = 0;
            s = s - 1;
            for (i = 0; i < m; i++)
            {
                if (s >= 9)
                    a[i] = 9;
                else
                    a[i] = s;
                s -= a[i];
            }
            a[m - 1] += 1;
            for (i = m - 1; i >= 0; i--)
                cout << a[i];
            cout << ' ';

            for (i = 0; i < m; i++)
                a[i] = 0;
            s = t;
            for (i = 0; i < m; i++)
            {
                if (s >= 9)
                    a[i] = 9;
                else
                    a[i] = s;
                s -= a[i];
            }
            for (i = 0; i < m; i++)
                cout << a[i];
            cout << '\n';
        }
        return 0;
    }

}