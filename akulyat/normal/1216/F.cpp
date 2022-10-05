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
vector<ll> r, ans;
bool viv = false;

void solve(ll room) {
    ll v1 = ans.back() + room + 1;
    ll wr = lower_bound(r.begin(), r.end(), room - k) - r.begin();
    if (wr != r.size())
        wr = r[wr];
    else
        wr = mod;
    ll v2 = kk * mod;
    if (viv)
        cout << "111111for " << room << ' ' << wr << endl;
    if (wr <= room + k) {
        if (viv)
            cout << "for " << room << ' ' << wr << endl;
        ll las = wr - k;
        las = max(las, 0ll);
        v2 = ans[las] + wr + 1;
    }
    ans.push_back(min(v1, v2));
}

int main() {
    //viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    string s;
    cin >> s;
    for (ll i = 0; i < n; i++)
        if (s[i] == '1')
            r.push_back(i);
    ans.push_back(0);
    for (ll i = 0; i < n; i++)
        solve(i);

    if (viv) {
        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
    cout << ans.back();


    return 0;
}
/**
9 2
000010000


**/