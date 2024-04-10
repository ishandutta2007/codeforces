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


ll n, i, j, m, k;
vector<ll> v;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 0; i < m; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    reverse(v.begin(), v.end());
    ll sh = k;
    ll ans = 0;
    while (v.size()) {
        ll add = 0;
        while (v.size() && v.back() <= sh)
            v.pop_back(), add++;
        if (add)
            ans++;
        sh += add;

        ll cf = 1;
        if (v.size()) {
            cf = max(cf, (v.back() - sh)/k - 3);
            if (v.back() > sh)
                sh += k * cf;
        }
/**
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
        cout << "Have " << sh << endl;
**/
    }
    cout << ans << endl;






    return 0;
}