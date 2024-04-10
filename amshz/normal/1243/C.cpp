# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
 
string bin(ll n){
	string ans = "";
	while (n > 0){
		if (n%2 == 0) ans = '0'+ans;
		else ans = '1'+ans;
		n /= 2;
	}
	return ans;
}
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}
 
const int xn = 1e6+10+10;
const int xm = 1e2+10;
 
bool p[xn];
vector <ll> v;
 
 
int main(){
	fast_io;
	
	ll n;
	cin >> n;
	
	for (ll i=2; i<=1e6; i++){
		if (i >= n) break;
		if (p[i]) continue;
		if (n%i == 0) v.pb(i);
		for (ll j=i+i; j<=1e6; j+=i) p[j] = true;
	}
	
	if (v.size() == 0) cout << n << endl;
	else if (v.size() == 1 and (n/v[0])%v[0] == 0) cout << v[0] << endl;
	else cout << 1 << endl;
	return 0;
}