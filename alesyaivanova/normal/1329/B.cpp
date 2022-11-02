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
    int d, m;
    cin >> d >> m;
    int cur = 1;
    int u = 3;
    for (; u <= d; u = u * 2 + 1)
        cur = ((cur + 1) * (u / 2 + 2) - 1 + m) % m;
    u /= 2;
    cur = ((cur + 1) * (d - u + 1) - 1 + m) % m;
    cout << cur << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}