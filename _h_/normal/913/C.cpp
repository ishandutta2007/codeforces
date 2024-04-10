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
	
	ll n, l;
	cin >> n >> l;
	vector<ll> cs(35, 1e18+3);
	rep(i,0,n) cin >> cs[i];
	rep(i,1,35) cs[i] = min(cs[i], 2*cs[i-1]);
	rrep(i,0,34) cs[i] = min(cs[i], cs[i+1]);
	ll ans = 1e18;
	ll cur = 0;
	rrep(i,0,35){
		if((1LL<<i) >= l) ans = min(ans, cur + cs[i]);
		else {
			l -= 1LL<<i;
			cur += cs[i];
		}
	}
	cout << ans << endl;
}