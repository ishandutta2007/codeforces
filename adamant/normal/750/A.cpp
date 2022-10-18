#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int rest = 60 * 4 - k;
    for(int i = 1; i <= n; i++)
    {
        if(5 * i > rest)
        {
            cout << i - 1 << endl;
            return 0;
        }
        rest -= 5 * i;
    }
    cout << n << endl;
    return 0;
}