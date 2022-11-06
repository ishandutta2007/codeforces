#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		ll m, k;
		cin >> m >> k;
		if(k > 1) k = 1 + (k-1)%2;
		vi a(m);
		trav(x, a) cin >> x;
		rep(_,0,k){
			int d = a[0];
			trav(x, a) d = max(d, x);
			trav(x, a) x = d-x;
		}
		trav(x, a) cout << x << " ";
		cout << endl;
	}
}