#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*for (int a = 0; a <= 100; ++a)
    {
        int ans = 0;
        for (int x = 0; x <= a; ++x)
        {
            if (a - (a ^ x) - x == 0)
            {
                ++ans;
            }
        }
        cout << a << ' ' << ans << endl;
    }*/
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int ans = 1;
        for (int i = 0; i < 30; ++i)
        {
            if ((x & (1 << i)))
            {
                ans *= 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}