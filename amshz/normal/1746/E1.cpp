// khodaya khodet komak kon
# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define pb                                              push_back
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
int power(int a, ll b, int md){
	int res = 1;
	while (b){
		if ((b & 1))
			res = 1ll * res * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return res;
}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;
 
int n;
vector<int> vec, nvec;
 
int main(){
	fast_io;
 
	cin >> n;
	for(int i = 1; i <= n; i++){
		vec.pb(i);
	}
	string res;
	while(SZ(vec) > 2){
		int x = SZ(vec) / 3;
		int y = (SZ(vec) - x) / 2;
		cout << "? " << x << " ";
		for(int i = 0; i < x; i++){
			cout << vec[i] << " ";
		}
		cout << "\n";
		cout.flush();
		cin >> res;
		int halat = 0;
		if(res == "NO"){
			cout << "? " << x << " ";
			for(int i = 0; i < x; i++){
				cout << vec[i] << " ";
			}
			cout << "\n";
			cout.flush();
			cin >> res;
			if(res == "NO"){
				halat = 1;
			}
		}
		if(halat != 1){
			cout << "? " << y << " ";
			for(int i = x; i < x + y; i++){
				cout << vec[i] << " ";
			}
			cout << "\n";
			cout.flush();
			cin >> res;
			if(res == "NO") halat = 2;
			else halat = 3;
		}
		if(halat == 1){
			nvec.clear();
			for(int i = x; i < SZ(vec); i++){
				nvec.pb(vec[i]);
			}
			vec = nvec;
		}
		if(halat == 2){
			nvec.clear();
			for(int i = 0; i < x; i++){
				nvec.pb(vec[i]);
			}
			for(int i = x + y; i < SZ(vec); i++){
				nvec.pb(vec[i]);
			}
			vec = nvec;
		}
		if(halat == 3){
			nvec.clear();
			for(int i = 0; i < x + y; i++){
				nvec.pb(vec[i]);
			}
			vec = nvec;
		}
	}
	if(SZ(vec) == 1){
		cout << "! " << vec[0] << "\n";
		cout.flush();
		cin >> res;
		return 0;
	}
	cout << "! " << vec[0] << "\n";
	cout.flush();
	cin >> res;
	if(res == ":)"){
		return 0;
	}
	cout << "! " << vec[1] << "\n";
	cout.flush();
	cin >> res;
	return 0;
	
 
	return 0;
}