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
vector<ll> m, p;
vector<multiset<ll, greater<ll>>> pr;
bool viv = false;

void solve() {
    cin >> n;
    pr.clear();
    pr.resize(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        m.push_back(a);
        p.push_back(b);
        pr[a].insert(b);
        sum += b;
    }
    for (ll i = 0; i < n; i++)
        if (pr[i].size()) {
            ll stay = *pr[i].begin();
            pr[i].erase(pr[i].begin());
            ll add = 1;
            for (auto j : pr[i])
                if (i + add < n)
                    pr[i+add].insert(j), add++;
            pr[i].clear();
            pr[i].insert(stay);
        }
    if (viv)
        for (ll i = 0; i < n; i++)
            if (pr[i].size())
                cout << i << ":" << (*pr[i].begin()) << ' ';
    vector<ll> res;
    for (ll i = n-1; i >= 0; i--)
        if (pr[i].size())
            res.push_back(*pr[i].begin());
    ll dec = 0;
    for (auto i : res)
        dec += i;
    if (viv)
        cout << "ans issssssssssss: ";
    cout << sum - dec << endl;
}



int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}