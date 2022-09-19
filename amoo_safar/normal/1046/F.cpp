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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;

ll a[MAXN];
ll b[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,f,x;
	cin >> n;
	for(int i = 0;i<n;i++) cin >> a[i];
	cin >> x >> f;
	for(int i = 0;i<n;i++)a[i] -= x;
	ll t= 0;
	ll g = x+f;
	for(int i = 0;i<n;i++){
		t += ((a[i] + g - 1)/g);
	}
	
	cout << t * f;
	return 0;

}