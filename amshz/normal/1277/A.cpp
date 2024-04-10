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
 
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}
 
const int xn = 2e5+10;
const int xk = 10;
 
int f(int r, int d){
	int g = 0;
	for (int i=0; i<r; i++) g = g*10+d;
	return g;
}
 
int main(){
	fast_io;
	//cout<<f(9, 9)<<endl;
	int t;
	cin>> t;
	while (t--){
		int n, m;
		cin>> n;
		if (n == 1e9){
			cout << 81<< endl;
			continue;
		}
		m = n;
		int r = 0;
		int mn = 11;
		while (m > 0){
			mn = min(mn, m%10);
			m /= 10;
			r++;
		}
		int ans = 9*r-9;
		for (int i=1;i<=9; i++) if (f(r, i) <= n) ans++;
		cout<<ans << endl;
		
	}
}