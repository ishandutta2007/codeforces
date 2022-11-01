#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 3e18 + 10;
const int M = 1e3 + 10;
const int N = 1e6 + 10;

ll a[N];

ll mn1[N], mx1[N];
ll mn2[N], mx2[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;
    fr(i, n)
        cin >> a[i];
    ll mx = *max_element(a, a + n);
    ll mn = *min_element(a, a + n);
    ll ans = a[0] * (p + q + r);

    fr(i, n) {
        mx1[i] = a[i];
        mn1[i] = a[i];
        if (i) mx1[i] = max(mx1[i], mx1[i - 1]);
        if (i) mn1[i] = min(mn1[i], mn1[i - 1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        mx2[i] = mn2[i] = a[i];
        if (i != n - 1) {
            mx2[i] = max(mx2[i + 1], mx2[i]);
            mn2[i] = min(mn2[i + 1], mn2[i]);
        }
    }

    fr(i, n) {
        ans = max(ans, a[i] * q + mn1[i] * p + mn2[i] * r);
        ans = max(ans, a[i] * q + mn1[i] * p + mx2[i] * r);
        ans = max(ans, a[i] * q + mx1[i] * p + mn2[i] * r);
        ans = max(ans, a[i] * q + mx1[i] * p + mx2[i] * r);
    }

    cout << ans;


}