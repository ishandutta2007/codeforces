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


ll n, i, j, sum;
vector<ll> m;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
        sum += a;
    }
    sort(m.begin(), m.end());
    vector<ll> v;
    for (ll i = 0; i < n-1; i++)
        if (m[i] == m[i+1])
            v.push_back(i);
    if (v.size() >= 2) {
        cout << "cslnb";
        exit(0);
    }
    if (v.size() == 1 && v[0] == 0 && m[0] == 0) {
        cout << "cslnb";
        exit(0);
    }
    if (v.size() == 1 && v[0] != 0 && m[v[0]] == m[v[0]-1] + 1) {
        cout << "cslnb";
        exit(0);
    }
    m[0] = 0;
    for (ll i = 1; i < n; i++) {
        if (m[i] != m[i-1])
            m[i] = m[i - 1] + 1;
    }
    for (auto i : m)
        sum -= i;
    sum &= 1;
    if (sum)
        cout << "sjfnb";
    else
        cout << "cslnb";





    return 0;
}