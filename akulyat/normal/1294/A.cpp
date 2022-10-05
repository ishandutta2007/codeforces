#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
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
const long long mod = 998244353;
const long long mod2 = 1e9+7;
const long long inf = ml * ml * ml + 7;
const int pc = 123457;
const int pc2 = 110329;
const ld cons = 1.95004;
const ld eps = 1e-4;
 
short n, k;
string s;
unordered_map<ll, ll> mp;
vector<short> p;
vector<ll> h, h2;
bool viv = false;


void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b + c + d) % 3) {
        cout << "NO\n";
        return;
    }
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    d -= (a - c);
    d -= (a - b);
    if (d < 0)
        cout << "NO\n";
    else    
        cout << "YES\n";    
}


int main() {
//  viv = true;
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}