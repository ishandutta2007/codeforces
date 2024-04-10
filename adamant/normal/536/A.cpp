#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    while(n--)
    {
        int l, t, m;
        cin >> l >> t >> m;
        int64_t st = a + 1LL * b * (l - 1);
        if(st > t)
        {
            cout << -1 << "\n";
            continue;
        }
        int L = l, R = l + 1e8;
        while(R - L > 1)
        {
            int M = (L + R) / 2;
            int64_t lt = a + 1LL * b * (M - 1);
            int64_t sum = 1LL * (st + lt) * (M - l + 1) / 2;
            if(1LL * t * min(m, M - l + 1) >= sum && t >= lt) L = M;
            else R = M;
        }
        cout << L << "\n";
    }
}