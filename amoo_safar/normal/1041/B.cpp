#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll g = __gcd(c,d);
    c/=g;
    d/=g;
    cout << min(a/c,b/d);
    return 0;

}