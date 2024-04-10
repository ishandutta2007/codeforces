# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 5e2+10;
const int xk = 1e2+10;

ll a[xn], b[xn];


int main(){
	fast_io;
	
	//cout << lcm(1, 2) << endl;
	ll r, c;
	cin >> r >> c;
	//
	//if (r > c) swap(r, c);
	
	for (ll i=1; i<=r; i++){
		a[i] = i+1;
	}
	b[1] = 1;
	for (ll j=2; j<=c; j++){
		b[j] = j+r;
	}
	if (r == 1 && c == 1){
		cout<< 0 << endl;
		return 0;
	}
	//for (int i=1; i<=r; i++){
	//	cout << a[i] << sep;
	//}
	//cout << endl;
	//for (int j=1; j<=c; j++) cout << b[j] << sep;
	//cout << endl;
	
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			
			
			if (c == 1) cout << lcm(i+c, j) << sep;
			else cout << lcm(i, j+r) << sep;
		}
		cout << endl;
	}
	
	
	return 0;
}