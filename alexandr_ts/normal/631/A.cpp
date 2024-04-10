#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll a[N], b[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        cin >> b[i];
    ll ans = 0;
    fr(l, n) {
        ll cur1 = 0, cur2 = 0;
        frab(r, l, n) {
            cur1 |= a[r];
            cur2 |= b[r];
            ans = max(ans, cur1 + cur2);
        }
    }
    cout << ans;

}