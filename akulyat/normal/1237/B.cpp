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
vector<ll> m, v;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    map<ll, ll> num;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        a--;
        m.push_back(a);
        num[a] = i;
    }
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        a--;
        a = num[a];
        v.push_back(a);
    }

    set<ll> s;
    ll ans = 0;
    reverse(v.begin(), v.end());
    for (auto i : v) {
        s.insert(i);
        if (*s.begin() != i)
            ans++;
    }

    cout << ans;



    return 0;
}