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
	vector<vi> ls(1e6);
	rep(i,0,n){
		int a;
		cin >> a;
		ls[a-1].push_back(i);
	}
	ll ans = 0;
	trav(v, ls) if(!v.empty()){
		v.push_back(n);
		int pr = -1;
		ll tot = ll(n)*n;
		trav(x, v){
			ll len = x-pr-1;
			tot -= len*len;
			pr = x;
		}
		ans += tot;
	}
	cout.precision(6);
	cout << ans*1./n/n << endl;
}