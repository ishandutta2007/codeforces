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


int n, q;




int main(){
	fast_io;
	
	cin >> q;
	while (q--){
		cin >> n;
		string a;
		if (n%2 == 0){
			//string a;
			for (int i = 0; i < n/2; i++) a += '1';
		}
		else{
			for (int i = 0; i < n/2-1; i++) a += '1';
			a = '7'+a;
		}
		cout << a << endl;
	}
	
	return 0;
}