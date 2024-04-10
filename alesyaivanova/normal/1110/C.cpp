#include <bits/stdc++.h>

using namespace std;

#define int long long

int ans[13] = {0, 1, 1, 1, 73, 89, 1, 4681, 1, 1, 299593, 178481, 1082401};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int a;
        cin >> a;
        int k = 0;
        int cnt = 0;
        while (k < a)
        {
            k = k * 2 + 1;
            cnt++;
        }
        if (k == a)
        {
            if (cnt % 2 == 1)
                cout << ans[cnt / 2] << "\n";
            else
                cout << k / 3 << "\n";
        }
        else
            cout << k << "\n";
    }
}