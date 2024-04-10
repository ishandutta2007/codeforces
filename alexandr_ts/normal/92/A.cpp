#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

main()
{
    int n, m;
    cin >> n >> m;
    int cur = 0;
    while (1)
    {
        cur = cur % n + 1;
        if (m >= cur)
            m -= cur;
        else
        {
            cout << m;
            return 0;
        }

    }
}