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

vector<ll> inter(vector<ll> a, vector<ll>b)
{
    vector<ll> c;
    for (ll i = 0; i < 2; i++)
        c.push_back(max(a[i], b[i]));
    for (ll i = 2; i < 4; i++)
        c.push_back(min(a[i], b[i]));
    if (c[0] > c[2])
        c[0] = c[2];
    if (c[1] > c[3])
        c[1] = c[3];
   return c;
}

ll sq(vector<ll> a) {
    ll res = (a[2] - a[0]) *(a[3] - a[1]);
    return res;
}

int main() {
   // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x1, x2, x3, x4, x5, x6;
    ll y1, y2, y3, y4, y5, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    ll s = (x2 - x1) *(y2 - y1);
    if (viv)
        cout << s << endl;

    s -= sq(inter({x1, y1, x2, y2}, {x3, y3, x4, y4}));
    if (viv)
        cout << s << endl;
    s -= sq(inter({x1, y1, x2, y2}, {x5, y5, x6, y6}));
    if (viv)
        cout << s << endl;
    s += sq(inter(inter({x3, y3, x4, y4}, {x5, y5, x6, y6}), {x1, y1, x2, y2}));
    if (viv)
        cout << s << endl;
    if (s > 0)
        cout << "YES";
    else
        cout << "NO";


    return 0;
}