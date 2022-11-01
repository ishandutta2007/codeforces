#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1003;
const int N = 1e6 + 10;

ll t[N];

ll f(ll m, ll n, ll k) {
    vector <ll> v;
    fr(i, k)
        fr(j, n)
            v.pb(t[i]);
    ll cnt = 0;
    fr(i, v.size())
        if (m >= v[i])
            m -= v[i], cnt++;
        else
            return cnt;
    return cnt;
}

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k, m;
    cin >> n >> k >> m;
    fr(i, k)
        cin >> t[i];
    ll sum = accumulate(t, t + k, 0ll);
    sort(t, t + k);

    ll ans = 0;
    for (ll full = 0; full <= n; full++) {
        if (m - sum * full >= 0)
            ans = max(ans, full * (k + 1) + f(m - sum * full, n - full, k));
    }
    cout << ans;
}