#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 5009;
int a[maxn];
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
            cout << i * 2 + 1 << " ";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int cur = i / 2;
        if (cur <= m)
        {
            a[i] = i + 1;
            m -= cur;
            continue;
        }
        int u = (i - m) * 2 + 1;
        a[i] = u;
        m = 0;
        u += i + 1;
        int kek = 1;
        for (int e = i + 1; e < n; e++)
        {
            a[e] = u * kek;
            kek += 2;
        }
        break;
    }
    if (m)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}