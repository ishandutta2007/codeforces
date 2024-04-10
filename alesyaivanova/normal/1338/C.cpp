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

void solve()
{
    int n;
    cin >> n;
    n--;
    int r = n % 3;
    n /= 3;
    int u = 0;
    while (n >= (1ll << u))
    {
        n -= (1ll << u);
        u += 2;
    }
    int a[3];
    a[0] = (1ll << u);
    a[1] = 2 * a[0];
    a[2] = 3 * a[0];
//    if (!n)
//    {
//        cout << a[r] << "\n";
//        return;
//    }
//    n--;
    int t = 0;
    while (n)
    {
        int kek = n % 4;
        int y = (1ll << t);
        if (kek == 0)
        {

        }
        if (kek == 1)
        {
            a[0] += 1 * y;
            a[1] += 2 * y;
            a[2] += 3 * y;
        }
        else if (kek == 2)
        {
            a[0] += 2 * y;
            a[1] += 3 * y;
            a[2] += 1 * y;
        }
        else if (kek == 3)
        {
            a[0] += 3 * y;
            a[1] += 1 * y;
            a[2] += 2 * y;
        }
        n /= 4;
        t += 2;
    }
    cout << a[r] << "\n";
}


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    for (int t = 1; t <= 30; t++)
//        solve(t);
    int t;
    cin >> t;
    while (t--)
        solve();
}