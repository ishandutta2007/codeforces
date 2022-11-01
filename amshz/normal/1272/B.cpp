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

string a;
int t[5];

int main(){
    fast_io;
    
    int qq;
    cin >> qq;
    while (qq--){
    	cin >> a;
    	
    	for (int i = 0; i < 5; i++) t[i] = 0;
    	
    	for (int i = 0; i < a.size(); i++){
    		if (a[i] == 'R') t[0]++;
    		if (a[i] == 'L') t[1]++;
    		if (a[i] == 'U') t[2]++;
    		if (a[i] == 'D') t[3]++;
		}
		
		int f = min(t[0], t[1]);
		int g = min(t[2], t[3]);
		
		if (!f && g) g = 1;
		else if (f && !g) f = 1;
		
		string ans = "";
		
		for (int i = 0; i < f; i++) ans += 'R';
		for (int i = 0; i < g; i++) ans += 'U';
		for (int i = 0; i < f; i++) ans += 'L';
		for (int i = 0; i < g; i++) ans += 'D';
		
		cout << ans.size() << endl;
		cout << ans << endl;
	}
    
    return 0;
}