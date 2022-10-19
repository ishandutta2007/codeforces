#include <bits/stdc++.h>
using namespace std;
const int N = 55;

int n;
char a[N];
int e[N];

int solv()
{
    cin >> n;
    int q0 = 0, q1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        int m = strlen(a);
        for (int j = 0; j < m; ++j)
        {
            if (a[j] == '0')
                ++q0;
            else
                ++q1;
        }
        e[i] = m;
    }
    sort(e, e + n);
    for (int i = 0; i < n; ++i)
    {
        int q = (e[i] / 2);
        for (int j = 0; j < q; ++j)
        {
            if (q0 >= 2)
            {
                q0 -= 2;
                continue;
            }
            if (q1 >= 2)
            {
                q1 -= 2;
                continue;
            }
            return i;
        }
        if (e[i] % 2 == 1)
        {
            if (q0 % 2 == 1)
            {
                q0--;
                continue;
            }
            if (q1 % 2 == 1)
            {
                q1--;
                continue;
            }
            if (q0 >= 1)
            {
                q0--;
                continue;
            }
            if (q1 >= 1)
            {
                q1--;
                continue;
            }
            return i;
        }
    }
    return n;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        cout << solv() << endl;
    return 0;
}