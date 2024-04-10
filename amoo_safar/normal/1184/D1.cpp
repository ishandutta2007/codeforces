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

vector<ll> A, B, C, D;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k, t;
	
	cin >> n >> k >> m >> t;
	ll ty, idx;
	for(int i = 1; i <= n; i++){
		if(i == k) A.pb(1);
		else A.pb(0);
	}
	for(int i = 0 ; i < t; i++){
		B.clear();
		C.clear();
		D.clear();
		for(auto x : A) D.pb(x);
		
		A.clear();
		cin >> ty >> idx;
		if(ty == 1){
			for(int i = 0; i < idx - 1; i++) A.pb(D[i]);
			A.pb(0);
			for(int i = idx - 1; i < D.size(); i++) A.pb(D[i]);	
		} else {
			ll sb = 0;
			ll sc = 0;
			for(int i = 0; i < idx; i++){
				B.pb(D[i]);
				sb += D[i];
			}
			for(int i = idx; i < D.size(); i++){
				C.pb(D[i]);	
				sc += D[i];
			}
			if(sb){
				for(auto x : B) A.pb(x);
			} else {
				for(auto x : C) A.pb(x);
			}
		}
		//for(auto x : A) cerr << x << ' ';
		//cerr << '\n';
		cout << A.size() << ' ';
		ll ind = 0;
		for(int i = 0; i < A.size(); i++) if(A[i] == 1){
			ind = i;
		}
		cout << ind + 1 << '\n';
	}
	
	return 0;
}