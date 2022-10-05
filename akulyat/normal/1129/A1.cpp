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


ll n, i, j, mx, k;
vector<pll> m;
vector<ll> v, v2, add;
vector<vector<ll>> have;
bool viv = false;

ll dist(ll a, ll b) {
    ll res = 0;
    res += b;
    res -= a;
    if (res < 0)
        res += n;
    return res;
}

void counter(ll st) {
    ll res = n;
    for (auto st2 : have[st]) {
        ll nres = dist(st, st2);
        res = min(res, nres);
    }
    add[st] = res;
//    cout << "More " << st << ' ' << res << endl;
}

ll solve(ll s) {
    ll ans = n * (mx - 1);
    ll addans = 0;
    for (auto st : v) {
        addans = max(addans, dist(s, st) + add[st]);
    }
    for (auto st : v2) {
        addans = max(addans, dist(s, st) + add[st] - n);
    }
    ans += addans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    have.resize(n);
    for (i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        m.push_back({a, b});
        have[a].push_back(b);
    }
    mx = 0;
    for (ll i = 0; i < n; i++)
        mx = max(mx, (ll)have[i].size());
    for (ll i = 0; i < n; i++)
        if (have[i].size() == mx)
            v.push_back(i);
    for (ll i = 0; i < n; i++)
        if (have[i].size() + 1 == mx && have[i].size())
            v2.push_back(i);
    add.resize(n, -1);
    for (auto s : v)
        counter(s);
    for (auto s : v2)
        counter(s);

    vector<ll> ans;
    for (ll i = 0; i < n; i++)
        ans.push_back(solve(i));

    for (auto i : ans)
        cout << i << ' ';





    return 0;
}