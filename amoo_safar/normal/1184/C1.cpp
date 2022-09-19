#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> edge;

const int Maxn = 2e5 + 10;
ll Inf = 1e18;
const int Log = 20;
const ll Sqrt = 1000000;
const ll Mod = 998244353LL;

ll mul(ll a, ll b){
	a%=Mod;
	b%=Mod;
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}


ll x[50], y[50];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= 4 * n + 1; i++) cin >> x[i] >> y[i];
	
	for(int i = 0; i <= 50; i++){
		for(int j = i + 1; j <= 50; j++){
			for(int k = 0; k <= 50; k++){
				ll l = k + (j - i);
				if(l > 50) continue;
				ll cnt = 0;
				for(int ii = 1; ii <= 4*n + 1; ii++){
					if(  ((i <= x[ii]) && (x[ii] <= j) && ((y[ii] == k) || (y[ii] == l)))  ||   ((k <= y[ii]) && (y[ii] <= l) && ((x[ii] == i) || (x[ii] == j)))  ) continue; 
					cnt ++;
				}
				if(cnt == 1){
					//cerr << i << " " << j << " " << k << " " << l << '\n';
					for(int ii = 1; ii <= 4*n + 1; ii++){
						if(((i <= x[ii]) && (x[ii] <= j) && ((y[ii] == k) || (y[ii] == l)))  ||   ((k <= y[ii]) && (y[ii] <= l) && ((x[ii] == i) || (x[ii] == j))) ) continue;
						cout << x[ii] << " " << y[ii] << '\n';
					}
					return 0;
				}
			}
		}
	} 
	return 0;
}