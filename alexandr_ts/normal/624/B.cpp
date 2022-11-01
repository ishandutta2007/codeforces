#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e3;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;

ll a[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    ll ans = 0;
    ll cur = a[0];
    fr(i, n) {
        ans += max(0ll, cur);
        cur = min(cur - 1, a[i + 1]);
    }
    cout << ans;

}