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
const long long N = 2e5 + 100;


ll n, i, j;
vector<ll> m;
bool viv = false;

void prepare() {
    vector<ll> l, r;
    l.resize(N, mod);
    r.resize(N, -1);
    vector<pair<pll, ll>> v;
    unordered_map<ll, ll> cnt;
    unordered_set<ll> s;

    for (ll i = 0; i < n; i ++) {
        ll val = m[i];
        cnt[val]++;
        l[val] = min(l[val], i);
        r[val] = max(r[val], i);
        s.insert(val);
    }
    for (auto val : s)
        v.push_back({{l[val], r[val]}, val});


    sort(v.rbegin(), v.rend());
    ll ans = 0;
    while (v.size()) {
        ll l_l = v.back().F.F;
        ll l_r = v.back().F.S;
        ll val = v.back().S;
        v.pop_back();

        vector <ll> used;
        used.push_back(cnt[val]);
        while (v.size() && v.back().F.F < l_r) {
            used.push_back(cnt[v.back().S]);
            l_r = max(l_r, v.back().F.S);
            v.pop_back();
        }
        ll lans = *max_element(used.begin(), used.end());
        ans += lans;
        if (viv)
            cout << lans << endl;
    }
    cout << n - ans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll q;
cin >> n >> q;
for (i = 0; i < n; i++) {
    ll a;
    cin >> a;
    m.push_back(a);
    }

prepare();



    return 0;
}