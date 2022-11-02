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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 0;
        return 0;
    }
    if (n == 1 || m == 1)
    {
        int u = 2;
        for (int i = 0; i < n; i++)
        {
            for (int e = 0; e < m; e++)
            {
                cout << u << " ";
                u++;
            }
            cout << "\n";
        }
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
        {
            int x = (i + 1) * (e + n + 1) /__gcd(i + 1, e + n + 1);
            cout << x << " ";
        }
        cout << "\n";
    }
}