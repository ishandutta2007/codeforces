#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int a[MAX_N];
int d[MAX_N];
int n, m, k;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
            d[i - 1] = a[i] - a[i - 1] - 1;
    }
    sort(d, d + n - 1);
    int ans = n;
    for (int i = 0; i < n - k; i++)
        ans += d[i];
    cout << ans;
}