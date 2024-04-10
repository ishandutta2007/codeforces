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
bool viv = false;

long long GCD(long long a, long long b)
{
if (a == 0 && b == 0)
    return 0;
while (a != 0&&b != 0)
    {
    if (a >= b)
        a %= b;
    else
        b %= a;
    }
return a + b;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (i = 0; i < n; i++)
        {
        ll a;
        cin >> a;
        m.push_back(a);
        }
    ll maxi = *max_element(m.begin(), m.end());
    ll g = *max_element(m.begin(), m.end());
    for (auto i : m)
        g = GCD(g, i);

    for (auto& i : m)
        i = maxi - i;

    ll y = *max_element(m.begin(), m.end());
    for (auto i : m)
        y = GCD(y, i);

    ll x = 0;
    for (auto i : m)
        x += i / y;

    cout << x << ' ' << y;






    return 0;
}