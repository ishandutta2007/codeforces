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


ll n, i, j, k;
vector<pair<pll, ll>> m;
vector<ll> ans;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        m.push_back({{a, b}, i});
    }
    sort(m.begin(), m.end());

    set <pll> s;
    for (int i = 0; i < n; i++) {
        ll l = m[i].F.F;
        ll r = m[i].F.S;
        ll num = m[i].S;
        while (s.size() && (*s.begin()).F < l)
            s.erase(s.begin());
        s.insert({r, num});
        if (s.size() > k) {
            auto p = *s.rbegin();
            s.erase(p);
            ans.push_back(p.S);
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i+1 << ' ';


    return 0;
}