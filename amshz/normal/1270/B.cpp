# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 1e9+7;

ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
 
const int xn = 2e5+10;
const int xm = 5e4+10;

int n, a[xn];

int main(){
    fast_io;
    
    int qq;
    cin >> qq;
    while (qq--){
    	cin >> n;
    	for (int i=0; i<n; i++) cin >> a[i];
    	
    	bool fl1 = false;
    	for (int i=0; i<n-1; i++){
    		if (abs(a[i]-a[i+1]) > 1){
    			cout << "YES" << endl;
    			cout << i+1 << sep << i+2 << endl;
    			fl1 = true;
    			break;
			}
		}
		
		if (fl1) continue;
    	cout << "NO" << endl;
    }
    	
    
    return 0;
}