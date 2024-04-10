#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int a, b;
        cin >> a >> b;
        if (a - b != 1)
        {
            cout << "NO\n";
            continue;
        }
        a += b;
        bool k = true;
        for (int i = 2; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                cout << "NO\n";
                k = false;
                break;
            }
        }
        if (k)
            cout << "YES\n";
    }
}