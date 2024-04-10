#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) return x = 1, y = 0, a;
    ll xx, yy;
    ll g = egcd(b, a%b, xx, yy);
    return x = yy, y = xx - a/b*yy, g;
}

ll dv(ll a, ll b) {
    return a/b - ((a < 0 != b < 0) && bool(a%b));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // HOME
    int N; cin >> N;
    vector<int> ds;
    int n = N;
    for(int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            ds.pb(i);
            while(n%i == 0) n /= i;
        }
    }
    if (n > 1) ds.pb(n);
    if (sz(ds) == 1) return cout << "NO", 0;
    int p1 = ds[0], p2 = ds[1];
    ll x0, y0;
    egcd(p2, p1, x0, y0);
    x0 *= N-1, y0 *= N-1;
    ll k = dv(y0-1, p2);
    ll x = x0+p1*k, y = y0-p2*k;
    cout << "YES\n2\n";
    cout << x << ' ' << N/p2 << '\n';
    cout << y << ' ' << N/p1;
}