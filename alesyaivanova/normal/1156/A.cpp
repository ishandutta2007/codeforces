#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss second
#define ff first

const int MAXN = 110;
int a[MAXN];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != 1 && a[i + 1] != 1)
        {
            cout << "Infinite";
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (a[i - 1] == 2)
                ans += 3;
            else
                ans += 4;
        }
        else if (a[i] == 2)
        {
            ans += 3;
            if (i - 2 >= 0 && a[i - 2] == 3)
                ans--;
        }
        else
            ans += 4;
    }
    cout << "Finite\n" << ans;
}