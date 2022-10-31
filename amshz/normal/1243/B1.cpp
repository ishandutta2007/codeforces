# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < int, bool> pib;

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

const int xn = 5e1+10;
const int xm = 1e2+10;

map <char, int> cnt;

char c[xn], d[xn];


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	string abc = "abcdefghijklmnopqrstuvwxyz";
	while (qq--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int flag = 0;
		pair <char, char> p;
		bool fl1 = true;
		for (int i=0; i<n; i++){
			if (a[i] == b[i]) continue;
			if (flag == 0){
				p.F = a[i], p.S = b[i];
				flag = 1;
				continue;
			}
			if (flag == 1){
				if (a[i] == p.F and b[i] == p.S) flag = 2;
				else{
					fl1 = false;
				}
				continue;
			}
			if (flag == 2) fl1 = false;
		}
		if (flag == 1) fl1 = false;
		if (fl1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}