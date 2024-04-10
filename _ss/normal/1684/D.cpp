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

const int N = 2e5 + 10;
int n, k;
ll a[N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += i - 1;
        sort(a + 1, a + n + 1);
        ll res = 1e18;
        a[0] = 0;
        for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
        for (int i = n - k; i <= n; ++i) res = min(res, a[i] - (ll)i * (i - 1) / 2);
        cout << res << "\n";
    }
    return 0;
}