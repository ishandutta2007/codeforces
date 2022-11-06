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
	while(n--){
		ll x,y,p,q;
		cin >> x >> y >> p >> q;
		if(q == 1){
			cout << (y*p == x ? 0 : -1) << endl;
			continue;
		}
		ll tot = 0;
		ll z = y-x, r = q-p;
		tot = max(tot, (r-1+z)/r*q);
		tot = max(tot, (p-1+x)/p*q);
		cout << tot-y << endl;
	}
}