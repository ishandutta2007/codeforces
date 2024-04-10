#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

const ll mx = 1000000000;

#define X first
#define Y second


void solve() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for (ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        if (x%3==0) a[i] = {0,i};
        else a[i] = {1,i};
    }
    sort(a.begin(),a.end());
    vector<ll> ans(n);
    for (ll i=0;i<n/2;i++)
    {
        ans[a[i].Y] = 1;
    }
    if (a[n/2-1].X==0) cout << 2 << "\n";
    else cout << 0 << "\n";
    for (ll i=0;i<n;i++) cout << ans[i];
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}