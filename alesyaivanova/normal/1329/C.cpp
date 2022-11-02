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

const int maxn = (1 << 22);
int a[maxn];
int sz[maxn];
int h, g;

bool update(int i, int cur_h)
{
    if (!a[i * 2] && !a[i * 2 + 1])
    {
        if (cur_h == g)
            return 0;
        a[i] = 0;
        return 1;
    }
    if (a[i * 2] > a[i * 2 + 1])
    {
        int e = a[i * 2];
        if (!update(i * 2, cur_h + 1))
            return 0;
        a[i] = e;
    }
    else
    {
        int e = a[i * 2 + 1];
        if (!update(i * 2 + 1, cur_h + 1))
            return 0;
        a[i] = e;
    }
    return 1;
}

void f(int i, int cur_h, vector<int>& kek)
{
    if (!a[i])
        return;
    while (true)
    {
        if (!update(i, cur_h))
            break;
        else
            kek.pb(i);
    }
    f(i * 2, cur_h + 1, kek);
    f(i * 2 + 1, cur_h + 1, kek);
}

void solve()
{
    cin >> h >> g;
    for (int i = 1; i < (1 << h); i++)
        cin >> a[i];
    vector<int> kek;
    f(1, 1, kek);
    int ans = 0;
    for (int i = 1; i < (1 << h); i++)
    {
        ans += a[i];
        a[i] = 0;
    }
    cout << ans << "\n";
    for (int i : kek)
        cout << i << " ";
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}