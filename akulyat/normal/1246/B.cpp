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
vector<ll> m, p;
vector<ll> will, pr;
vector<vector<pll>> del;
unordered_map<ll, ll> cnt;
bool viv = false;

vector<long long> erat(long long last)
{
vector<bool> bad;
vector<long long> r;
for (long long i = 0; i < last + 10; i++)
    bad.push_back(true);
for (long long i = 2; i <= last; i++)
    if (bad[i])
        {
        long long j = 2;
        while (j * i <= last)
            {
            bad[j * i] = false;
            j++;
            }
        r.push_back(i);
        }
return r;
}


void calc(ll c) {
    ll wc = c;
    for (auto d : p)
        if (c % d == 0) {
            ll kol = 0;
            while (c % d == 0)
                c /= d, kol++;
            kol %= k;
            if (kol)
                del[wc].push_back({d, kol});
            for (int i = 0; i < kol; i++)
                will[wc] *= d;
        }
    if (c != 1) {
        ll kol = 1;
        ll d = c;
        c /= d;
        kol %= k;
        if (kol)
            del[wc].push_back({d, kol});
        for (int i = 0; i < kol; i++)
            will[wc] *= d;
    }
    ll para = 1;
    for (auto p : del[wc]) {
        for (int i = 0; i < k - p.S; i++) {
            para *= p.F;
            if (para > ml)
                return;
        }
    }
    pr[wc] = para;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    p = erat(32*100);
    del.resize(100*kk+200);
    will.resize(100*kk+200, 1);
    pr.resize(100*kk+200, -1);
    for (ll i = 1; i < 100*kk + 100; i++)
        calc(i);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (viv)
            cout << i << ' ' << a << ' ' << will[a] << endl;
        m.push_back(will[a]);
        cnt[will[a]]++;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll a = m[i];
        ll p = pr[a];
        ans += cnt[p];
        if (a == p)
            ans--;
        if (viv)
            cout << "on " << i << " that is " << a << " with pair " << p << " see that ans is " << ans << endl;
    }
    ans /= 2;
    cout << ans << endl;








    return 0;
}