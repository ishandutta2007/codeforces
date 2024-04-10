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

const int maxn = 2e5 + 9;
int n, m;
int a[maxn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n > m)
    {
        cout << 0;
        return 0;
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        x[i] = a[i] % m;
    }
    uniq(x);
    if ((int)x.size() != n)
    {
        cout << 0;
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < i; e++)
            ans = (ans * abs(a[i] - a[e])) % m;
    }
    cout << ans;
}