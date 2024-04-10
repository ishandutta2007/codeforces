#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vi a(n), b(n);
	rep(i,0,n) cin >> a[i] >> b[i];

	ll w = ll(a[0])*b[0];
	rep(i,1,n) w = gcd(w, ll(a[i])*b[i]);

	if(w == 1){
		cout << -1 << endl;
		return 0;
	}

	ll w1 = gcd(w, a[0]);
	if(w1 > 1) w = w1;
	else w = gcd(w, b[0]);

	for(ll i = 2; ll(i)*i <= w; ++i){
		if(w % i == 0){
			cout << i << endl;
			return 0;
		}
	}
	cout << w << endl;
}