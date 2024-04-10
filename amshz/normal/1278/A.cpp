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
str bin(ll n){
	str a = "";
	while (n > 0){
		if (n%2) a = '1'+a;
		else a = '0'+a;
		n /= 2;
	}
	return a;
}

const int xn = 2e5+10;
const int xm = 1e2+10;

string a, b;
vector <char> c;

bool check(int l, int r){
	vector <char> d;
	for (int i=l; i<=r; i++) d.pb(b[i]);
	sort(d.begin(), d.end());
	for (int i=0; i<d.size(); i++) if (d[i] != c[i]) return false;
	return true;
}


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	while (qq--){
		cin >> a >> b;
		if (b.size() < a.size()){
			cout << "NO" << endl;
			continue;
		}
		c.resize(0);
		for (int i=0; i<a.size(); i++) c.pb(a[i]);
		sort(c.begin(), c.end());
		bool fl1 = false;
		for (int i=0; i<=b.size()-a.size(); i++){
			if (check(i, i+a.size()-1)) fl1 = true;
		}
		//cout << "ans : " << endl;
		if (fl1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}