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

const int xn = 4e5+10;
const int xm = 5e4+10;


bool p[xn];
vector <int> pr;


int main(){
	fast_io;
	
	for (int i=2; i<=4e5; i++){
		if (p[i]) continue;
		pr.pb(i);
		for (int j=2; j<=4e5/i; j++) p[i*j] = true;
	}
	
	int n;
	cin >> n;
	
	if (n%2 == 0){
		cout << n+4 << sep << 4 << endl;
		return 0;
	}
	cout << n+15 << sep << 15 << endl;
	return 0;
	
	return 0;
}