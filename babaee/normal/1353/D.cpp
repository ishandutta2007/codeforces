/*
    Soheil Mohammadkhani
    Div3. Contest :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a[MAXN] = {0};
ll med(ll l, ll r) {
    if ((r - l + 1) % 2 == 1) {
        return (l + r) / 2;
    }

    return (l + r - 1) / 2;
}

ll solve() {
    // X: size, Y: End
    ll n;
    cin >> n;
    fill(a, a + n + 1, 0);
    priority_queue<pll> q;
    q.push({n, 0});
    ll k = 1;
    while (!q.empty()) {
        pll t = q.top();
//        debug_p(q.top());
        q.pop();
        t.Y *= -1;
        ll sz = t.X;
        ll l = t.Y;
        ll r = t.Y + t.X - 1;
        a[med(l, r)] = k;
//        debug2(l);
//        debug(r);
//        debug(med(l, r));
        k++;
        if (sz == 1) continue;
        if (sz > 2) q.push({floor(ld(sz - 1) / 2), -1 * l});
        q.push({ceil(ld(sz - 1) / 2), -1 * (med(l, r) + 1)});
    }

    for (int i = 0; i < n; i++) cout << a[i] << sep;
    cout << endl;
    return 0;
}

int main() {
    fast_io;


//    cout << med(3, 5) << endl;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}