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


ll n, i, j;
vector<vector<ll>> m;
map<ll, ll> cnt;
map<pll, vector<ll>> trip;
bool viv = false;

void add(ll a, ll b, ll c) {
    trip[{a, b}].push_back(c);
    trip[{b, a}].push_back(c);
    trip[{c, b}].push_back(a);
    trip[{b, c}].push_back(a);
    trip[{a, c}].push_back(b);
    trip[{c, a}].push_back(b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n - 2; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
//        a--, b--, c--;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        m.push_back({0, a, b, c});
        add(a, b, c);
    }
    for (auto &p : m) {
        p[0] += cnt[p[1]];
        p[0] += cnt[p[2]];
        p[0] += cnt[p[3]];
    }
    sort(m.begin(), m.end());

    vector<pll> v;
    for (ll j = 1; j < 4; j++) {
        ll p = m[0][j];
        v.push_back({cnt[p], p});
    }
    sort(v.begin(), v.end());

    vector<ll> ans;
    for (auto i : v)
        ans.push_back(i.S);

    for (ll i = 3; i < n; i++) {
        ll a = ans[i - 1];
        ll b = ans[i - 2];
        ll w = ans[i - 3];
        ll c = trip[{a, b}][0];
        if (c == w)
            c = trip[{a, b}][1];
        ans.push_back(c);
    }

    for (auto i : ans)
        cout << i << ' ';







    return 0;
}