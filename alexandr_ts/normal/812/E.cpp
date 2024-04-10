#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;

ll a[N], par[N];
vector <ll> g[N];
ll lvl[N];

void dfs(ll v, ll l) {
    lvl[v] = l;
    for (auto t: g[v])
        dfs(t, l + 1);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n - 1) {
        cin >> par[i + 1];
        par[i + 1]--;
        g[par[i + 1]].pb(i + 1);
    }

    dfs(0, 1);

    if ((*max_element(lvl, lvl + n)) % 2)
        fr(i, n)
            lvl[i]++;
    vector <ll> even, odd;
    fr(i, n)
        if (lvl[i] % 2 == 0)
            even.pb(i);
        else
            odd.pb(i);

    map <ll, ll> cnt;
    fr(i, odd.size())
        cnt[a[odd[i]]]++;

    ll xs = 0;
    fr(i, even.size())
        xs ^= a[even[i]];

    ll ans = 0;
    fr(i, even.size()) {
        ll t = xs ^ a[even[i]];
        if (cnt.count(t))
            ans += cnt[t];
    }

    if (xs == 0) {
        ll sz = even.size();
        ans += (sz * (sz - 1)) / 2;
        ll sz2 = odd.size();
        ans += (sz2 * (sz2 - 1)) / 2;
    }

    cout << ans;
}