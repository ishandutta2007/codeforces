#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define pf emplace_front
#define ff first
#define ss second
#define pii pair<int, int>

bool a[50][10000];
int m, n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int e = 0; e < k; e++)
        {
            int x;
            cin >> x;
            x--;
            a[i][x] = true;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int e = 0; e < m; e++)
        {
            bool u = false;
            for (int j = 0; j < n; j++)
                u |= (a[i][j] & a[e][j]);
            if (!u)
            {
                cout << "impossible";
                return 0;
            }
        }
    }
    cout << "possible";
}