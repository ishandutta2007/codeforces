#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    ll p = 0, q = n;
    for(ll i = 0; i < n; i++) {
        p += (3 - 2 * n + 4 * i) * a[i];
    }
    ll g = __gcd(p, q);
    p /= g; q /= g;
    cout << p << ' ' << q;
}