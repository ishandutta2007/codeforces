#include <bits/stdc++.h>
using namespace std;

int d(int x)
{
    int ans;
    while (x)
    {
        ans = x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    int da, db;
    cin >> da >> db;
    for (int a = 1; a <= 1000; ++a)
    {
        if (d(a) == da)
        {
            if (d(a + 1) == db)
            {
                cout << a << ' ' << a + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}