#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

int c[N];
bool solv()
{
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; ++i)
        c[i] = 2;
    int r = -1;
    for (int k = '0'; k <= '9'; ++k)
    {
        for (int i = r + 1; i < n; ++i)
        {
            if (a[i] == k)
            {
                c[i] = 1;
                r = i;
            }
        }
        bool z = true;
        char v = '0';
        for (int i = 0; i < n; ++i)
        {
            if (c[i] == 1)
            {
                if (a[i] < v)
                {
                    z = false;
                    break;
                }
                v = a[i];
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (c[i] == 2)
            {
                if (a[i] < v)
                {
                    z = false;
                    break;
                }
                v = a[i];
            }
        }
        if (z)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        if (solv())
        {
            for (int i = 0; i < n; ++i)
                cout << c[i];
            cout << endl;
        }
        else
            cout << '-' << endl;
    }
    return 0;
}