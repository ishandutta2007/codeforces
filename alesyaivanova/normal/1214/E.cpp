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

const int MAXN = 200009;
pii d[MAXN];
int n;
int a[MAXN];
vector<int> g[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i].ff;
        d[i].ss = i;
    }
    sort(d, d + n);
    int y = 1;
    int len = d[n - 1].ff;
    int pt = len + 1;
    a[0] = d[n - 1].ss * 2 + 1;
    a[len] = d[n - 1].ss * 2 + 2;
    for (int i = n - 2; i >= 0; i--)
    {
        int c = d[i].ss * 2 + 1;
//        cout << d[i].ss << "\n\n";
//        for (int w = 0; w < pt; w++)
//            cout << a[w] << " ";
//        cout << "\n";
        if (y < len)
        {
            a[y] = c;
            if (pt - y == d[i].ff)
            {
                a[pt] = c + 1;
                pt++;
            }
            else
                g[y + d[i].ff - 1].pb(c + 1);
            y++;
        }
        else
        {
            if (d[i].ff == 1)
            {
                a[pt] = c;
                a[pt + 1] = c + 1;
                pt += 2;
            }
            else
            {
                g[0].pb(c);
                g[d[i].ff - 2].pb(c + 1);
            }
        }
    }
    for (int i = 0; i < pt; i++)
    {
        if (i > 0)
            cout << a[i - 1] << " " << a[i] << "\n";
        for (int to : g[i])
            cout << a[i] << " " << to << "\n";
    }
}