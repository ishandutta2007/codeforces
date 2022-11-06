#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<ll> vi;

ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	while(a){
		b %= a;
		swap(a, b);
	}
	return b;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vi as(n), bs(m);
	trav(x, as) cin >> x;
	trav(x, bs) cin >> x;


	ll g = 0;
	rep(i,1,n) g = gcd(g, as[i] - as[0]);

	trav(x, bs) cout << gcd(x + as[0], g) << " ";
	cout << endl;
}