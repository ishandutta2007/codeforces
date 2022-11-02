#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 100009;
int cnt[MAXN];
int a[MAXN];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    int ans = n * (n + 1) / 2;
    int cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur += cnt[i];
        ans += cur * i;
    }
    cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += cnt[i];
        ans += cur * (n - i - 1);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x = min(a[i], a[i + 1]);
        int y = max(a[i], a[i + 1]);
        ans -= x * (x + 1) / 2 + (n - y - 1) * (n - y) / 2 + (y - x - 1) * (y - x) / 2;
    }
    int x = a[0];
    ans -= x * (x + 1) / 2 + (n - x - 1) * (n - x) / 2;
    x = a[n - 1];
    ans -= x * (x + 1) / 2 + (n - x - 1) * (n - x) / 2;
    cout << ans;
}