#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

main()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << -1;
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
            cout << 2 * i << " " << 2 * i - 1 << " ";
    }
}