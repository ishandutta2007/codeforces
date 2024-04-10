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

ll a[5], b[5];

ll f(){
	ll s = 0;
	s += abs(a[0]-a[1]);
	s += abs(a[0]-a[2]);
	s += abs(a[1]-a[2]);
	
	return s;
}

int main(){
    fast_io;
    
    int qq;
    cin >> qq;
    while (qq--){
    	cin >> b[0] >> b[1] >> b[2];
    	
    	ll mn = 1e18;
    	
    	for (int i=-1; i<=1; i++){
    		for (int j=-1; j<=1; j++){
    			for (int k=-1; k<=1; k++){
    				a[0] = b[0]+i, a[1] = b[1]+j, a[2] = b[2]+k;
    				mn = min(mn, f());
				}
			}
		}
		
		cout << mn << endl;
	}
    
    return 0;
}