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
vector<ll> v;
vector<vector<ll>> m;
bool viv = false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i = 0; i < n; i++)
    {
    m.push_back({});
    m.back().resize(n);
    for (auto &i : m.back())
        cin >> i;
    }

v.resize(n);
v[0] = ll(sqrt((m[0][1] * m[0][2]) / m[1][2]));
for (ll i = 1; i < n; i++)
    v[i] = m[0][i] / v[0];
for (auto i : v)
    cout << i << ' ';





    return 0;
}