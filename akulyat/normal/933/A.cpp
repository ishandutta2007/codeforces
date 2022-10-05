#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, ans;
vector<ll> m, o;
bool viv = false;

void prepare() {
    o.push_back(0);
    for (auto i : m)
        o.push_back(o.back() + (i == 1));
}

ll sum(ll l, ll r, ll t) {
    if (l > r)
        return 0;
    ll len = r - l + 1;
    ll res = o[r + 1] - o[l];
    if (t == 2)
        res = len - res;
    return res;
}

void solve(ll l) {
    ll ones = 0;
    ll lans = 0;
    ll res = 0;
    for (ll r = l; r < n; r++) {
        if (m[r] == 1)
            lans++;
        else
            ones++;
        lans = max(lans, ones);
        ll lres = lans;
        lres += sum(0, l-1, 1);
        lres += sum(r + 1, n - 1, 2);
  //      cout << l << ' ' << r << ' ' << lres << endl;
        res = max(res, lres);
    }
    ans = max(res, ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    prepare();
    for (ll i = 0; i < n; i++)
        solve(i);

    cout << ans << endl;
    return 0;
}