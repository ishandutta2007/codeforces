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
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int x;
        cin >> x;
        int q = x % 7;
        if (q == 0 || x < 15)
        {
            cout << "NO\n";
            continue;
        }
        int y = x / 7;
        if (y % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}