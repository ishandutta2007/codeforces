# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair <char, int> pc;

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

const int xn = 2e5+10;
const int xm = 1e2+10;

//vector <pc> v1, v2;


int main(){
	fast_io;
	int qq;
	cin >> qq;
	while (qq--){
		string a, b;
		cin >> a >> b;
		vector <pc> v1, v2;
		for (int i=0; i<a.size(); i++){
			int s = v1.size()-1;
			if (i == 0) v1.pb({a[0], 1});
			else{
				if (a[i] == a[i-1]) v1[s].S++;
				else v1.pb({a[i], 1});
			}
		}
		for (int i=0; i<b.size(); i++){
			int s = v2.size()-1;
			if (i == 0) v2.pb({b[0], 1});
			else{
				if (b[i] == b[i-1]) v2[s].S++;
				else v2.pb({b[i], 1});
			}
		}
		bool fl1 = true;
		if (v1.size() != v2.size()){
			cout << "NO" << endl;
			continue;
		}
		for (int i=0; i<v1.size(); i++)
			if (v1[i].F != v2[i].F or v2[i].S < v1[i].S) fl1 = false;
		if (fl1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}