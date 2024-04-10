# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
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
 
const int xn = 3e5+10;
const int xm = 5e4+10;

int n, m, c[xn], b[xn], d[xn];
pair <int, int> a[xn];

int main(){
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i].F, a[i].S = i;
    
    for (int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	x--, y--;
    	
    	if (a[y].F > a[x].F) swap(x, y);
    	
    	if (a[x].F > a[y].F) b[x]++;
	}
	
	sort(a, a+n);
	
	for (int i = 0; i < n; i++){
		if (i == 0 || a[i].F > a[i-1].F) c[i] = i;
		else c[i] = c[i-1];
		
		d[a[i].S] = c[i] - b[a[i].S];
		
		//cout << c[i] << sep;
	}
	//cout << endl;
	
	for (int i = 0; i < n; i++) cout << d[i] << sep;
	cout << endl;
    
    return 0;
}