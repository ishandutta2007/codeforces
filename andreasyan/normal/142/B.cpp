#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;

int main()
{
    int q1 = 0, q2 = 0;
    cin >> n >> m;
    if (n == 1 || m == 1)
    {
        cout << n * m << endl;
        return 0;
    }
    if (n == 2)
    {
        for (int i = 0; i < m; ++i)
        {
            if ((i / 2) % 2)
                q1 += 2;
            else
                q2 += 2;
        }
        cout << max(q1, q2) << endl;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((i / 2) % 2)
                q1 += 2;
            else
                q2 += 2;
        }
        cout << max(q1, q2) << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) % 2)
                ++q1;
            else
                ++q2;
        }
    }
    cout << max(q1, q2) << endl;
    return 0;
}