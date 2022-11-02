#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb mplace_back
#define pf emplace_front
#define pii pair<int, int>
#define mp make_pair

const int MAXN = 100009;
int a[MAXN];
int b[MAXN];
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    if (a[n - 1] > b[0])
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        ans += a[i] * m;
    for (int i = 0; i < m; i++)
        ans += b[i];
    int cnt = m;
    int e = n - 1;
    while (cnt > 0)
    {
        if (e < 0)
            break;
        if (a[e] == b[0])
        {
            ans -= min(m, cnt) * a[e];
            cnt -= min(m, cnt);
            e--;
        }
        else
        {
            ans -= min(m - 1, cnt) * a[e];
            cnt -= min(m - 1, cnt);
            e--;
        }
    }
    if (cnt)
        cout << -1;
    else
        cout << ans;
}