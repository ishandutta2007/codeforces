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


ll n, i, j, p, k;
vector<ll> m;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> p >> k;
    vector<ll> res;
    res.push_back(p);
    while (res.back() >= k || res.back() < 0) {
        ll was = res.back();
        res.back() %= k;
        if (res.back() < 0)
            res.back() += k;
        res.push_back((was - res.back()) / -k);
    }

    cout << res.size() << endl;
    for (auto i : res)
        cout << i << ' ';



    return 0;
}