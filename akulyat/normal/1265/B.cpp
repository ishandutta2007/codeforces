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
vector<ll> m;
set<ll> s;
string ans;
bool viv = false;

void add() {
    ll l = *s.begin();
    ll r = *s.rbegin();
    if (r - l + 1 == s.size())
        ans += '1';
    else
        ans += '0';
}

void solve() {
    cin >> n;
    m.clear();
    vector<ll> pl(n, -1);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        a--;
        m.push_back(a);
        pl[a] = i;
    }
    s.clear();
    ans.clear();
    for (auto i : pl) {
        s.insert(i);
        add();
    }
    ans += '\n';
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();



    return 0;
}