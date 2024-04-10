#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 200009;
int h[MAX_N];
int n, k;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h, h + n);
    int c = 0;
    int ans = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        int h1 = h[i] - h[i - 1];
        if (h1 == 0)
            continue;
        if (c + h1 * (n - i) < k)
        {
            c += h1 * (n - i);
            continue;
        }
        int cur = (k - c) / (n - i);
        ans++;
        h1 -= cur;
        cur = k / (n - i);
        ans += h1 / cur;
        c = (h1 % cur) * (n - i);
    }
    if (c != 0)
        ans++;
    cout << ans;
}