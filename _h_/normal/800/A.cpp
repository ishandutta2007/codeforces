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

const ld eps = 1e-6;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,p;
	cin >> n >> p;
	vi a(n), b(n);
	rep(i,0,n) cin >> a[i] >> b[i];
	ll A = 0;
	trav(x, a) A += x;
	if(A <= p){
		cout << -1 << endl;
		return 0;
	}
	ll consumed = A - p;
	ld lo = 0, hi = n*100000. + 10;
	while(hi-lo > eps){
		ld mi = (hi + lo)/2;
		
		ld fr = 0;
		rep(i,0,n){
			fr += min(a[i]*mi, (ld)b[i]);
		}
		if(fr >= consumed*mi){
			lo = mi;
		} else {
			hi = mi;
		}
	}
	cout.precision(6);
	cout << lo << endl;
}