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
const int xm = 1e6+10;

ll n, sz[xn], p[xm], ans, t;
vector <int> s[xn];
bool f[xn];


int main(){
    fast_io;
    
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> sz[i];
    	int x;
    	for (int j = 0; j < sz[i]; j++) cin >> x, s[i].pb(x);
    	bool fl1 = true;
    	for (int j = 1; j < sz[i]; j++) if (s[i][j] > s[i][j-1]) fl1 = false;
    	f[i] = fl1;
    	if (fl1) p[s[i][0]]++, p[1000001]--;
    	else t++;
	}
	for (int i = 1; i <= 1e6; i++) p[i] += p[i-1];
	
	//for (int i = 0; i <= 5; i++) cout << p[i] << sep;
	//cout << endl;
	
	for (int i = 0; i < n; i++){
		if (f[i]) ans += p[s[i][sz[i]-1]];
	}
	
	cout << n*n-ans << endl;
    
    return 0;
}