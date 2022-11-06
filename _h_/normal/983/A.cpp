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

ll gcd(ll a, ll b){
	while( a!=0 && b!=0 ){
		a %= b;
		swap(a,b);
	}
	return a+b;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(_,0,n){
		ll p, q, b;
		cin >> p >> q >> b;

		ll d = gcd(p, q);
		q /= d;
		
		while(true){
			b = gcd(q, b);
			if(b == 1) break;
			q /= b;
		}

		if(q==1) cout << "Finite" << endl;
		else   cout << "Infinite" << endl;
	}
}