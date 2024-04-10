#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
 
const ld PI = 3.14159265359;
 
const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
 
ll a[MAXN];
ll b[MAXN];
ll g[MAXN];

void SIK(){
	cout << "NO";
	exit(0);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x,y,z;
    cin >> x>> y >> z;
    ll a, b, c;
    cin >> a>>b >> c;
    if(x > a) SIK();
    a -= x;
    if(y > a + b) SIK();
    ll t = min(a, y);
     a -= t;
     y -= t;
     b -= y;
    if(z > a + b+ c) SIK();
    cout << "YES";
	return 0;
}