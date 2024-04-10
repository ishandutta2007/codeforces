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

const int maxn = 30;
int a[30][30];
int n;

signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int u = 1;
    for (int e = 1; e < n; e += 2)
    {
        int x = u;
        for (int i = 0; i < n; i++)
        {
            a[i][e] = x;
            x *= 2;
        }
        u *= 4;
    }
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
            cout << a[i][e] << " ";
        cout << endl;
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int k;
        cin >> k;
        int u = 1;
        int x = 0, y = 0;
        cout << x + 1 << " " << y + 1 << endl;
        while (x != n - 1 || y != n - 1)
        {
            if (x == n - 1)
            {
                y++;
                cout << x + 1 << " " << y + 1 << endl;
                continue;
            }
            if (y == n - 1)
            {
                x++;
                cout << x + 1 << " " << y + 1 << endl;
                continue;
            }
            if (k & u)
            {
                if (a[x + 1][y] == u)
                    x++;
                else
                    y++;
            }
            else
            {
                if (a[x + 1][y] == u)
                    y++;
                else
                    x++;
            }
            cout << x + 1 << " " << y + 1 << endl;
            u *= 2;
        }
    }
}