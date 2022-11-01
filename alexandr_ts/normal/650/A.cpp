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

pr l[N], r[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    map <ll, ll> x1, y1;
    map <pr, ll> pr1;
    fr(i, n) {
        ll x, y;
        cin >> x >> y;
        x1[x]++;
        y1[y]++;
        pr1[mp(x, y)]++;
    }
    ll ans = 0;
    for (auto it: x1)
        ans += it.second * (it.second - 1) / 2;
    for (auto it: y1)
        ans += it.second * (it.second - 1) / 2;
    for (auto it: pr1)
        ans -= it.second * (it.second - 1) / 2;
    cout << ans;

}