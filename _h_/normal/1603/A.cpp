#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll lcm(ll a, ll b){
	return a / __gcd(a, b) * b;
}

bool solve(){
	int n;
	cin >> n;
	vector<ll> as(n);
	trav(a, as) cin >> a;
	ll f = 1;
	rep(i,2,n+2){
		ll a = as[i-2];
		f = lcm(f, i);
		if(f > ll(1e9)) return true;
		if(a % f == 0) return false;
	}
	return true;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		cout << (solve() ? "YES" : "NO" ) << endl;
	}
}