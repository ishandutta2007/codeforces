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
const int xn = 2e5+10;
const int xk = 1e2+10;

ll fn1(char q){
	if (q == '1') return 0;
	if (q == '2') return 1;
	if (q == '3') return 2;
}


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	while (qq--){
		ll x;
		cin >> x;
		string a;
		cin >> a;
		ll n = a.size();
		for (ll i=0; i<x; i++){
			///cout << a << endl;
			//cout << n << endl;
			if (a.size() >= x){
				n += (fn1(a[i]) * (n - i - 1) + md) % md;
				n = (n+md)%md;
			}
			else{
				n += (fn1(a[i]) * (n - i - 1) + md) % md;
				n = (n+md)%md;
				string b = "";
				if (a[i] == '1') continue;
				for (int j=i+1; j<a.size(); j++) b += a[j];
				for (int j=0; j<fn1(a[i]); j++) a += b;
			}
		}
		cout << n << endl;
		
	}
	return 0;
}