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
int p[maxn];
int n, k;
int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int pr = -1;
    int kek = 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] > n - k)
        {
            kek += p[i];
            if (pr != -1)
                ans = (ans * (i - pr)) % mod;
            pr = i;
        }
    }
    cout << kek << " " << ans;
}