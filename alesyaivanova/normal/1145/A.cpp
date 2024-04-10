#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int len = n; len >= 1; len /= 2)
    {
        for (int j = 0; j < n; j += len)
        {
            bool u = true;
            for (int i = j + 1; i < j + len; i++)
            {
                if (a[i] < a[i - 1])
                    u = false;
            }
            if (u)
            {
                cout << len;
                return 0;
            }
        }
    }
}