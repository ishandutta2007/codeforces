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
vector<ll> m, p, rm;
bool viv = false;

ll sum(ll l, ll r) {
    return p[r+1] - p[l];
}

ll rsum(ll l, ll r) {
    l = n - 1 - l;
    r = n - 1 - r;
    swap(l, r);
    return p[r+1] - p[l];
}

bool can(ll dif) {
    ll ma = 0;
    for (ll i = 0; i < n; i++) {
        while (ma < n && m[ma] <= m[i] + dif)
            ma++;
        ll res = i * m[i] - sum(0, i - 1);
        res += sum(ma, n - 1) - (n - ma) * (m[i] + dif);

//        cout << dif << ' ' << i << ' ' << ma << " is " << res << endl;

        if (res <= k)
            return true;
    }
    ma = 0;
    for (ll i = 0; i < n; i++) {
        while (ma < n && rm[ma] >= rm[i] - dif)
            ma++;
        ll res = rsum(0, i - 1) - rm[i] * i;
        res += (n - ma) * (rm[i] - dif) - rsum(ma, n - 1);
//        cout << dif << ' ' << i << ' ' << ma << " is " << res << endl;

        if (res <= k)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    sort(m.begin(), m.end());
    rm = m;
    sort(rm.rbegin(), rm.rend());
    p.push_back(0);
    for (auto i : m)
        p.push_back(p.back() + i);
    ll l = -1;
    ll r = mod;
    while (l + 1 < r) {
        ll mi = l + r >> 1;
        if (can(mi))
            r = mi;
        else
            l = mi;
    }

    cout << r << endl;




    return 0;
}