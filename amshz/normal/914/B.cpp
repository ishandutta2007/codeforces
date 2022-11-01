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

const int xn = 1e5+10;
const int xm = 1e2+10;

int a[xn], cnt[xn];


int main(){
	fast_io;
	
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int mx = 0, t = 0;
	for (int i=0; i<n; i++) mx = max(mx, a[i]);
	for (int i=0; i<n; i++) if (mx == a[i]) t++;
	if (t%2){
		cout << "Conan" << endl;
	}
	else{
		sort(a, a+n);
		for (int i=0; i<n; i++) cnt[a[i]]++;
		for (int i=0; i<n; i++){
			if (cnt[a[i]]%2){
				cout << "Conan" << endl;
				return 0;
			}
		}
		cout << "Agasa" << endl;
	}
	return 0;
	
	return 0;
}