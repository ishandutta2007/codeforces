#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 2e5 + 10;

int a[N];

bool ok(ll n, ll k) {
    if (k >= 1000000) return false;
    return (k * (k + 1)) / 2 <= n;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if (!ok(n, k)) {
        cout << -1;
        return 0;
    }
    ll t = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (ok(n / i, k))
                t = max(t, (ll)i);
            if (ok(i, k))
                t = max(t, n / i);
        }
    }
    vector <ll> ans(k, 0);
    fr(i, k - 1)
        ans[i] = i + 1;
    ans[k - 1] = n / t - k * (k - 1) / 2;
    for (auto it: ans)
        cout << it * t << " ";
}