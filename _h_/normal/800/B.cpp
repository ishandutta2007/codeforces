#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

typedef long double ld;

typedef complex<ld> P;

ld area(P a, P b, P c){
	b -= a, c -= a;
	return abs((b*conj(c)).imag())/2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<P> poly(n+2);
	trav(p, poly){
		int x, y;
		cin >> x >> y;
		p = P(x,y);
	}
	rep(i,0,2) poly[i+n] = poly[i];
	ld ans = 1e12;
	rep(i,0,n){
		ld h = 2*area(poly[i], poly[i+1], poly[i+2])/abs(poly[i]-poly[i+2]);
		ans = min(ans, h/2);
	}
	cout.precision(7);
	cout << ans << endl;
}