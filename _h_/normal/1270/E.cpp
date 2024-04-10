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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vi x(n), y(n);
	rep(i,0,n) cin >> x[i] >> y[i];

	while(true){
		rep(i,1,n)
			if( (x[i]+y[i]+x[0]+y[0])%2 )
				goto ok;
		if((x[0]+y[0])%2) trav(a, x) a++;
		rep(i,0,n){
			int xx = x[i]+y[i], yy = x[i]-y[i];
			x[i] = xx/2, y[i] = yy/2;
		}
		continue;
		ok: break;
	}
	vi a;
	rep(i,0,n) if((y[i]+x[i])%2) a.push_back(i);
	cout << sz(a) << endl;
	trav(x, a) cout << 1+x << " ";
	cout << endl;
}