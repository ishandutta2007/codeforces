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

const int maxn = 609;

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    if (a < b)
        swap(a, b);
    int t = 0;
    while (a <= n)
    {
        int c = a + b;
        b = a;
        a = c;
        t++;
    }
    cout << t << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}