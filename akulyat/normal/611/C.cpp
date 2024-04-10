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


ll n, i, j, m;
vector<vector<ll>> f, d, r;
bool viv = false;

void prepare() {
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m - 1; j++)
            if (f[i][j] && f[i][j+1])
                r[i][j] = 1;
    }
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < m; j++)
            if (f[i][j] && f[i + 1][j])
                d[i][j] = 1;
    }
    for (ll i = 0; i < r.size(); i++) {
        for (ll j = 0; j < r[i].size(); j++) {
            if (i)
                r[i][j] += r[i-1][j];
            if (j)
                r[i][j] += r[i][j-1];
            if (i && j)
                r[i][j] -= r[i-1][j-1];
        }
    }
    for (ll i = 0; i < d.size(); i++) {
        for (ll j = 0; j < d[i].size(); j++) {
            if (i)
                d[i][j] += d[i-1][j];
            if (j)
                d[i][j] += d[i][j-1];
            if (i && j)
                d[i][j] -= d[i-1][j-1];
        }
    }
}

ll sum(vector<vector<ll>> &p, ll a, ll b, ll c, ll d) {
    ll res = 0;
    if (c >= 0 && d >= 0)
        res += p[c][d];
    if (a && d >= 0)
        res -= p[a-1][d];
    if (b && c >= 0)
        res -= p[c][b-1];
    if (a && b)
        res += p[a-1][b-1];
    return res;
}

void answer() {
    ll a, b, c, d1;
    cin >> a >> b >> c >> d1;
    a--, b--, c--, d1--;
    ll ans = 0;
    ans += sum(r, a, b, c, d1-1);
    ans += sum(d, a, b, c-1, d1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        f.push_back({});
        r.push_back({});
        r.back().resize(m - 1);
        if (i) {
            d.push_back({});
            d.back().resize(m);
        }
        string a;
        cin >> a;
        for (auto i : a)
            f.back().push_back(i == '.');
    }
    prepare();

    ll q;
    cin >> q;
    while (q--)
        answer();



    return 0;
}