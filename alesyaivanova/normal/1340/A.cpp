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

const int maxn = 1e5 + 9;
int a[maxn];
int n;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pr = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1] + 1)
        {
            if (a[i] > pr)
            {
                cout << "No\n";
                return;
            }
            pr = a[i];
        }
    }
    cout << "Yes\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}