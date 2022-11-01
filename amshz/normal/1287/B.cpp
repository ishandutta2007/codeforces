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

int n, m, ans;
string a[xn], abc = "SET";
map <string, bool> mp;


char fn1(char a1, char a2){
	if (a1 == a2) return a1;
	for (int i = 0; i < 3; i++){
		if (a1 != abc[i] && a2 != abc[i]) return abc[i];
	}
}

int main(){
    fast_io;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]] = true;
    
    //cout << fn1('S', 'E') << endl;
    
    
    for (int i = 0; i < n; i++){
    	for (int j = i+1; j < n; j++){
    		string c = "";
    		for (int k = 0; k < m; k++) c += fn1(a[i][k], a[j][k]);
    		if (mp[c]) ans++;
		}
	}
	
	cout << ans/3 << endl;
    
    return 0;
}