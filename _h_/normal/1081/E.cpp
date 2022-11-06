#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

void fail(){
	cout << "No" << endl;
	exit(0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> xs(n);
	rep(i,0,n/2) cin >> xs[2*i+1];
	
	ll cur = 0;
	rep(i,0,n/2){
		ll x = xs[2*i+1];
		ll mi = cur+1, hi = cur+2;
		while(true){
			if(hi > 5e5) fail();
			else if(hi*hi - mi*mi > x)
				++mi;
			else if(hi*hi - mi*mi < x)
				++hi;
			else {
				xs[2*i] = mi*mi - cur*cur;
				cur = hi;
				goto foo;
			}
		}
		foo: ;
	}
	cout << "Yes" << endl;
	trav(x, xs) cout << x << ' ';
	cout << endl;
}