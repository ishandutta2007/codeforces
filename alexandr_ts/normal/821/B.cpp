#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const int N = 2e2 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll m, b;
    cin >> m >> b;
    ll ans = 0;
    frab(y, 0, b + 1) {
        ll x = (b - y) * m;
        ans = max(ans, (x * (x + 1)) / 2 * (y + 1) + (y * (y + 1)) / 2 * (x + 1));
    }
    cout << ans;
}