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


ll n, i, j, sum;
vector<ll> mm;
bool viv = false;

ll mv(vector<pll> &v, ll kol) {
    int sum = 0;
    ll mid = -1;
    bool was = false;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i].F;
        if (!was && sum > kol / 2)
            mid = v[i].S, was = true;
    }
    ll res = 0;
    for (ll i = 0; i < v.size(); i++)
        res += abs(mid - v[i].S) * v[i].F;
    if (viv) {
        cout << "Moves for ";
        for (auto p : v)
            cout << p.F << ' ' << p.S << "; ";
        cout << endl;
        cout << "Kol " << kol << endl;
        cout << "Mid " << mid << endl;
        cout << "Res " << res << endl;
    }
    return res;
}

ll solve(ll in) {
    ll kol = sum / in;
    if (kol == 1)
        return inf;
    auto m = mm;
    vector<pair<ll, vector<pll>>> v;
    v.resize(in, {kol, {}});
    ll now = 0;
    for (ll i = 0; i < n; i++) {
        while (m[i]) {
            if (v[now].F == 0)
                now++;
            ll mn = min(v[now].F, m[i]);
            m[i] -= mn;
            v[now].F -= mn;
            v[now].S.push_back({mn, i});
        }
    }
    if (viv) {
        ll cnt = 0;
        for (auto l : v) {
            cout << cnt << ": ";
            for (auto p : l.S)
                cout << p.F << ' ' << p.S << "; ";
            cnt++;
            cout << endl;
        }
    }
    ll ans = 0;
    for (auto &l : v)
        ans += mv(l.S, kol);
    if (viv)
        cout << "__________ for " << kol << " want " << ans << endl;
    return ans;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        mm.push_back(a);
        sum += a;
    }
    if (sum == 1) {
        cout << -1;
        exit(0);
    }

    ll ans = inf;
    for (ll i = 1; i*i <= sum; i++)
        if (sum % i == 0) {
            ans = min(solve(i), ans);
            ans = min(solve(sum / i), ans);
        }
    cout << ans;






    return 0;
}