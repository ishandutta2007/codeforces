#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e5 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll pows[N];

bool good(ll mask, ll n) {
    ll x = 0;
    fr(i, 11)
        x += pows[i] * bool((1ll << i) & mask);
    return x <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    pows[0] = 1;
    frab(i, 1, 12)
        pows[i] = pows[i - 1] * 10;
    ll n, ans = 0;
    cin >> n;
    fr(mask, (1ll << 11ll)) {
        ans += good(mask, n);
        //if (good(mask, n))
         //   cout << mask << endl;
    }
    cout << ans - 1;

}