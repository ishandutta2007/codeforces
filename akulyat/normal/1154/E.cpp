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
vector<ll> m;
set<pll> tos, por;
vector<bool> ans;
bool viv = false;
bool now = 0;

void work() {
    auto p = *tos.begin();
    tos.erase(tos.begin());
    auto rp = p;
    swap(rp.F, rp.S);

    auto z = por.find(rp);
    auto zr = z, zl = z;
    zr++;
    zl--;

    vector<pll> er;
    er.push_back(*z);

    for (ll i = 0; i < k; i++)
        if (zr != por.end())
            er.push_back(*zr), ++zr;
    if (z != por.begin())
        for (ll i = 0; i < k; i++) {
                if (zl == por.begin())
                    i = k;
                if (i < k || zl == por.begin())
                    er.push_back(*zl), --zl;
            }

    for (auto rp : er) {
        ans[rp.F] = now;
        por.erase(rp);
        auto p = rp;
        swap(p.F, p.S);
        tos.erase(p);
    }

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ans.resize(n);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
        tos.insert({-a, i});
        por.insert({i, -a});
    }
    while(tos.size())
        work(), now ^= 1;

    for (auto i : ans)
        cout << char('1' + i);

    return 0;
}