#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(auto &it: a)
        cin >> it;
    if(n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }
    if(n == 2)
    {
        cout << max(a[0], a[1]) << ' ' << max(a[0], a[1]) << endl;
        return 0;
    }
    int odd[n - 1];
    int even[n - 1];
    for(int i = 0; i < n; i++)
    {
        even[i] = max(a[i], a[i + 1]);
        odd[i] = max(min(a[i], a[i + 1]), min(a[i + 1], a[i + 2]));
    }
    int lo = (n - !(n % 2)) / 2 - 1, ro = lo + !(n % 2);
    int le = (n - n % 2) / 2 - 1, re = le + (n % 2);
    int mxo = 0, mxe = 0;
    for(int k = 0; k <= n - 3; k++)
    {
        if((n - k) % 2 == 0)
        {
            mxe = max({mxe, even[le], even[re]});
            cout << mxe << ' ';
            le--, re++;
        }
        else
        {
            mxo = max({mxo, odd[lo], odd[ro]});
            cout << mxo << ' ';
            lo--, ro++;

        }
    }
    cout << *max_element(a, a + n) << ' ' << *max_element(a, a + n) << endl;
}