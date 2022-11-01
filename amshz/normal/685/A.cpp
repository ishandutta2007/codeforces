# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;

# define endl		 '\n'
# define sep		 ' '
# define F 			 first
# define S 			 second
# define pb			 push_back
# define fast_io 	 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b);}
ll pw(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pw(a*a, b/2)+md)%md;
	else return (a*pw(a*a, b/2)+md)%md;
}

const int xn = 2e5+10;
const int xm = 5e4+10;

ll n, m, t, ans;

ll ted(ll a){
	ll s = 0;
	while (a > 0) a /= 7, s++;
	return s;
}
ll td(ll a){
	ll s = ted(a);
	if (ted(a-1) != s && s > 1) s--;
	return s;
}
ll tab(string a, ll l, ll r){
	ll s = 0;
	for (ll i=l; i<=r; i++){
		s *= 7;
		s += ll(a[i]-'0');
	}
	return s;
}
void fn1(string a){
	ll sz = a.size();
	if (sz == t){
		//cout << a << endl;
		if (tab(a, ll(0), td(n)-1) < n &&  tab(a, td(n), sz-1) < m) ans++;//, cout << a << endl;
		return;
	}
	//for (int i=0; i<10; i++) cnt[i] = 0;
	//for (int i=0; i<sz; i++) cnt[a[i]-'0']++;
	for (ll i=0; i<7; i++){
		bool fl1 = true;
		for (int j=0; j<sz; j++) if (ll(a[j]-'0') == i) fl1 = false;
		
		string b = a;
		b += char('0'+i);
		if (fl1) fn1(b);
	}
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	t = td(n) + td(m);
	
	
	if (t > 7 || t == 0){
		cout << 0 << endl;
		return 0;
	}
	
	
	fn1("");
	
	cout << ans << endl;
	
	return 0;
}