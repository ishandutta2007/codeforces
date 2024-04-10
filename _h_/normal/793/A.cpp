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
	
	int n, k;
	cin >> n >> k;
	vi as(n);
	trav(x, as) cin >> x;
	trav(x, as) if((x-as[0])%k){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	int mn = 1e9+1;
	trav(x, as) mn = min(x, mn);
	trav(x,as) ans += (x-mn)/k;
	cout << ans << endl;
}