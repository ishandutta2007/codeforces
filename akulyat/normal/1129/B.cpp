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
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k;
    if (k < ml) {
        cout << 1 << endl;
        cout << -k << endl;
        exit(0);
    }
    n = 1500;
//    n = 3;
//    (s - 1) * (n + 1)
    ll s = k + n + 1;

    vector<ll> ans;
    ans.resize(n + 1);
    ans[0] = -1;
    for (ll i = 1; i < ans.size(); i++) {
        ans[i] = min(ml, s);
        s -= ans[i];
    }

    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';






    return 0;
}