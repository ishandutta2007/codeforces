#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
int a[N];

map<int, int> mp;

int dpr[N];
int r[N];
int dpl[N];
int l[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = m; i >= 1; --i)
    {
        if (mp.find(a[i] + (m - i) - 1) != mp.end())
            dpr[i] = dpr[mp[a[i] + (m - i) - 1]];
        else
            dpr[i] = min(n, a[i] + (m - i));
        mp[a[i] + (m - i)] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (mp.find(i + 1 + m - 1) != mp.end())
            r[i] = dpr[mp[i + 1 + m - 1]];
        else
            r[i] = min(n, i + 1 + m);
    }
    mp.clear();
    for (int i = m; i >= 1; --i)
    {
        if (mp.find(a[i] - (m - i) + 1) != mp.end())
            dpl[i] = dpl[mp[a[i] - (m - i) + 1]];
        else
            dpl[i] = max(1, a[i] - (m - i));
        mp[a[i] - (m - i)] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (mp.find(i - 1 - m + 1) != mp.end())
            l[i] = dpl[mp[i - 1 - m + 1]];
        else
            l[i] = max(1, i - 1 - m);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += (r[i] - l[i] + 1);
    cout << ans << endl;
    return 0;
}