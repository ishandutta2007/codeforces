#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> P;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<P> m;
vector<pll> ans;
bool viv = false;

ll solve2(vector<pll> v) {
//    sort(v.begin(), v.end());
    if (viv) {
        cout << "Solve2\n";
        for (auto i : v)
            cout << i.S << ' ';
        cout << endl;
    }

    for (int i = 0; i < (ll)v.size() - 1; i+=2)
        ans.push_back({v[i].S, v[i+1].S});
    if (v.size() & 1)
        return v.back().S;
    return -1;
}

ll solve(vector<P> v) {
    vector <pair<pll, ll>> z;
    for (auto e : v)
        z.push_back({{e.F.S, e.S.F}, e.S.S});
    if (viv) {
        cout << "Solve\n";
        for (auto i : z)
            cout << i.S << ' ';
        cout << endl;
    }


//    sort(z.begin(), z.end());
    vector <vector<pll>> z2;
    for (int i = 0; i < z.size(); i++) {
        if (i == 0 || z[i].F.F != z[i-1].F.F)
            z2.push_back({});
        z2.back().push_back({z[i].F.S, z[i].S});
    }
    vector<ll> ost;
    for (auto vec : z2) {
        ll a = solve2(vec);
        if (a != -1)
            ost.push_back(a);
    }
    for (int i = 0; i < (ll)ost.size() - 1; i+=2)
        ans.push_back({ost[i], ost[i+1]});
    if (ost.size() & 1)
        return ost.back();
    return -1;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        m.push_back({{a, b}, {c, i+1}});
    }
    sort(m.begin(), m.end());
    vector <vector<P>> v;
    for (int i = 0; i < n; i++) {
        if (i == 0 || m[i].F.F != m[i-1].F.F)
            v.push_back({});
        v.back().push_back(m[i]);
    }
    vector<ll> ost;
    for (auto i : v) {
        ll a = solve(i);
        if (a != -1)
            ost.push_back(a);
    }

    for (ll i = 0; i < ost.size(); i+=2)
        ans.push_back({ost[i], ost[i+1]});

    for (auto i : ans)
        cout << i.F << ' ' << i.S << endl;

    return 0;
}