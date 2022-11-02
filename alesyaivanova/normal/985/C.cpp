#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    int j = upper_bound(a, a + m, a[0] + l) - a;
    if (j < n)
    {
        cout << 0;
        return 0;
    }
    long long ans = 0;
    ans += a[0];
    int pr = 0;
    int mod = n - 1;
    for (int i = 1; i < j; i++)
    {
        if (a[i] - a[pr] > l)
        {
            if (pr == i - 1)
            {
                cout << 0;
                return 0;
            }
            ans += a[i - 1];
            pr = i - 1;
            mod--;
        }
        if (i - pr == k || i + mod == j)
        {
            ans += a[i];
            pr = i;
            mod--;
        }
    }
    cout << ans;
}