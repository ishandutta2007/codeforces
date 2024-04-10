#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1000;
const ll INF = 2e15 + 10;
const ll MOD = 1e9 + 7;
const ll MAX = 50002;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    //string s;
    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    ll minNum = a[0];
    ll ans = INF;

    for (ll k = min(MAX, minNum); k >= 1 && ans == INF; k--) {
        bool ok = true;
        for (ll i = 0; i < n && ok; i++) {
            ll t1 = a[i] / k;
            ll r1 = a[i] % k;
            if (t1 < r1 && (a[i] + k) / (k + 1) < (k + 1) * ((a[i] + k) / (k + 1)) - a[i])
                ok = false;
        }
        if (ok) {
            ll cnt = 0;
            fr(i, n)
                cnt += (a[i] + k) / (k + 1);
            ans = cnt;
        }
    }

    vector <ll> ks;
    for (ll t = 1; t < MAX / 2; t++) {
        if (a[0] / t - 1 >= MAX)
            ks.pb(a[0] / t - 1);
        if (a[0] / t >= MAX)
            ks.pb(a[0] / t);
        if (a[0] / t + 1 >= MAX)
            ks.pb(a[0] / t + 1);
    }

    for (ll i = 0; i < ks.size(); i++) {
        bool ok = true;
        ll k = ks[i];
        for (ll i = 0; i < n && ok; i++) {
            ll t1 = a[i] / k;
            ll r1 = a[i] % k;
            if (t1 < r1 && (a[i] + k) / (k + 1) < (k + 1) * ((a[i] + k) / (k + 1)) - a[i])
                ok = false;
        }
        if (ok) {
            ll cnt = 0;
            fr(i, n)
                cnt += (a[i] + k) / (k + 1);
            ans = min(ans, cnt);
        }
    }
    cout << ans;
}