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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 1e15 + 1;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll ax, ay;
    cin >> ax >> ay;
	ll bx, by;
    cin >> bx >> by;
    ll cx, cy;
    cin >> cx >> cy;
	if((cx < ax) and (bx > ax)) return cout << "NO", 0;
	if((cx > ax) and (bx < ax)) return cout << "NO", 0;
	
	if((cy < ay) and (by > ay)) return cout << "NO", 0;
	if((cy > ay) and (by < ay)) return cout << "NO", 0;
	cout << "YES";
	return 0;
}