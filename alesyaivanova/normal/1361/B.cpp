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

const int maxn = 1e6 + 9;
int k[maxn];
int n, p;
int mod = 1e9 + 7;

int binpow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x % mod;
    int z = binpow(x, y / 2);
    z = (z * z) % mod;
    if (y % 2)
        z = (z * x) % mod;
    return z;
}

void solve()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    if (p == 1)
    {
        if (n % 2 == 0)
            cout << "0\n";
        else
            cout << "1\n";
        return;
    }
    sort(k, k + n);
    reverse(k, k + n);
    int pt = 0;
    while (pt < n)
    {
//        cout << pt << "\n";
//        if (pt + 1 < n && k[pt] == k[pt + 1])
//        {
//            pt += 2;
//            continue;
//        }
        int cur = k[pt];
        int cnt = 1;
        for (int e = pt + 1; e <= n; e++)
        {
            if (e < n)
            {
                while (cur > k[e] && cnt <= n - e)
                {
                    cur--;
                    cnt *= p;
                }
            }
            if (e == n || cnt > n - e)
            {
                int ans = binpow(p, k[pt]);
                for (int j = pt + 1; j < n; j++)
                    ans = (ans - binpow(p, k[j]) + mod) % mod;
                cout << ans << "\n";
                return;
            }
            cnt--;
            if (!cnt)
            {
                pt = e + 1;
                break;
            }
        }
    }
    cout << "0\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}