#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-all-loops")

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
vector<ll> mm, pr;
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



ll mv(vector<pll> &v, ll kol) {
    ll sum = 0;
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
    return res;
}

ll solve(ll kol) {
    if (kol == 1)
        return inf;
    vector<ll> m = mm;
    for (auto &i : m)
        i %= kol;
    vector<pair<ll, vector<pll>>> v;
    v.push_back({kol, {}});
    int now = 0;
    for (ll i = 0; i < n; i++) {
        while (m[i]) {
            ll mn = min(v[now].F, m[i]);
            m[i] -= mn;
            v[now].F -= mn;
            v[now].S.push_back({mn, i});
            if (v[now].F == 0)
                now++, v.push_back({kol, {}});
        }
    }
    while (v.size() > now)
        v.pop_back();
    ll ans = 0;
    for (auto &l : v)
        ans += mv(l.S, kol);
    return ans;
}

ll solve2(ll kol) {
    if (kol == 1)
        return inf;
    vector<ll> m = mm;
    for (auto &i : m)
        i %= kol;
    vector<ll> where;
    vector<ll> coor, sums;
    where.push_back(-1);
    coor.push_back(0);
    sums.push_back(0);
    int now = 0;
    ll lsum = 0;
    ll ans = 0;
    ll mid = (kol + 1)/2;
    for (ll i = 0; i < n; i++) {
        while (m[i]) {
            ll mn = min(kol - lsum, m[i]);
            if (where.back() != -1) {
                ans += mn * (i - where.back());
            }
            if (where.back() == -1)
                coor.back() += mn * i, sums.back() += mn;
            m[i] -= mn;
            lsum += mn;
            if (where.back() == -1 && lsum >= mid) {
                where.back() = i;
                ans += sums.back() * i - (coor.back());
            }
//            cout << "After " << i << " " << lsum << ' ' << where.back() << ' ' << ans << endl;
            if (lsum == kol)
                lsum = 0, where.push_back(-1), coor.push_back(0), sums.push_back(0);
        }
    }
//    cout << kol << " want " << ans << endl;
    return ans;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pr = erat(ml + 10);
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

    ll ssum = sum;
    for (auto i : pr)
        while ((ssum % i) == 0)
            ssum /= i;
    if (ssum != 1)
        pr.push_back(ssum);

    ll ans = inf;
    for (auto d : pr)
        if (sum % d == 0) {
            ans = min(solve2(d), ans);
        }

    cout << ans;






    return 0;
}