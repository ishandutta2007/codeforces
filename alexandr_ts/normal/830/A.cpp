#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 7;
const int M = 2e6 + 3;
const ld PI = acos(-1);
const int POW = 25;
const ll MOD = 1e9 + 7;

const int N = 3e5 + 10;

ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);

    ll n, k, p;
    cin >> n >> k >> p;
    fr(i, n)
        cin >> a[i];
    fr(i, k)
        cin >> b[i];

//    vector <int> a1, a2, b1, b2;
//
//    fr(i, n)
//        if (a[i] <= p)
//            a1.pb(p - a[i]);
//        else
//            a2.pb(a[i] - p);
//
//    fr(i, k)
//        if (b[i] <= p)
//            b1.pb(p - b[i]);
//        else
//            b2.pb(b[i] - p);

    sort(a, a + n);
    sort(b, b + k);

    ll ans = INF;

    fr(l, k - n + 1) {
        ll mx = 0;
        fr(i, n) {
            mx = max(mx, abs(b[i + l] - a[i]) + abs(b[i + l] - p));

        }
        ans = min(ans, mx);
    }

    cout << ans;

}