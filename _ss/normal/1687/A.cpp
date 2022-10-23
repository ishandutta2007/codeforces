#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (k > n)
        {
            ll res = 0;
            for (int i = 1; i <= n; ++i) res += a[i];
            res += (ll)k * n - (ll)n * (n + 1) / 2;
            cout << res << "\n";
        }
        else
        {
            ll res = 0;
            ll sum = 0;
            for (int i = 1; i <= k; ++i) sum += a[i];
            res = sum;
            for (int i = k + 1; i <= n; ++i)
            {
                sum = sum + a[i] - a[i - k];
                res = max(res, sum);
            }
            cout << res + (ll)k * (k - 1) / 2 << "\n";
        }
    }
    return 0;
}