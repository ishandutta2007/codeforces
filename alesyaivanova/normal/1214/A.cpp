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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d, e;
    cin >> n >> d >> e;
    e *= 5;
    int ans = n;
    for (int k = 0; k <= 1000; k++)
    {
        if (d * k <= n)
            ans = min(ans, (n - d * k) % e);
    }
    cout << ans;
}