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


ll n, i, j, t;
vector<ll> ans;
bool viv = false;
set<pll> sit, ready, stand;
set<ll> standn;

pll swp(pll p) {
    swap(p.F, p.S);
    return p;
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    ans.resize(n);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sit.insert({a, i});
    }
    stand.insert(*sit.begin());
    sit.erase(sit.begin());
    standn.insert((*stand.begin()).S);

    ll cur_t = 0;
    while (stand.size()) {
        if (viv) {
            cout << "stand: ";
            for (auto i : stand)
                cout << i.F << ' ' << i.S << "; ";
            cout << endl;
            cout << "ready: ";
            for (auto i : ready)
                cout << swp(i).F << ' ' << swp(i).S << "; ";
            cout << endl;
            cout << "sit: ";
            for (auto i : sit)
                cout << i.F << ' ' << i.S << "; ";
            cout << endl;
        }
        auto now = *stand.begin();
        cur_t = max(cur_t, now.F);
        cur_t += t;
        ans[now.S] = cur_t;

        while (!sit.empty() && (*sit.begin()).F <= cur_t) {
            auto add = *sit.begin();
            sit.erase(sit.begin());
            if (add.S < *standn.begin()) {
                stand.insert(add);
                standn.insert(add.S);
            } else
                ready.insert(swp(add));
        }


        standn.erase((*stand.begin()).S);
        stand.erase(stand.begin());
        if (stand.empty()) {
            if (!ready.empty()) {
                stand.insert(swp(*ready.begin()));
                standn.insert((*stand.begin()).S);
                ready.erase(ready.begin());
            } else if (!sit.empty()) {
                stand.insert(*sit.begin());
                sit.erase(sit.begin());
            }
        }
    }

    for (auto i : ans)
        cout << i << ' ';


    return 0;
}