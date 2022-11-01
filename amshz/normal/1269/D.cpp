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

const int xn = 3e5+10;
const int xm = 5e4+10;

ll a[xn];

int main(){
	fast_io;
	
	int n;
	cin >> n;
	ll t1 = 0, t2 = 0;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++){
		t1 += a[i]/2, t2 += a[i]/2;
		if (a[i]%2){
			if (i%2 == 0) t1++;
			else t2++;
		}
	}
	cout << min(t1, t2) << endl;
	
	
	return 0;
}