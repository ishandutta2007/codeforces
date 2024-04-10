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
        int n;
        cin >> n;
        vi p(n + 1), l(n + 1), r(n + 1);
        for (int i = 2; i <= n; ++i) cin >> p[i];
        for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
        vll dp(n + 1);
        int res = 0;
        for (int i = n; i; --i)
            if (dp[i] < l[i]) res++, dp[p[i]] += r[i];
            else dp[p[i]] += min(dp[i], (ll)r[i]);
        cout << res << "\n";
    }
    return 0;
}