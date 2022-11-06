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
	vi a(n);
	trav(x, a) cin >> x;
	vector<ll> pre(n);
	rep(i,0,n-1){
		pre[i+1] = pre[i] + abs(a[i+1]-a[i])*(i%2==0 ? 1 : -1);
	}
	ll ans = -1e10, mn = 1e16, mx = -1e16;
	rrep(i,0,n){
		if(i%2 == 0){
			ans = max(ans, mx - pre[i]);
		} else {
			ans = max(ans, pre[i] - mn);
		}
		mn = min(mn, pre[i]);
		mx = max(mx, pre[i]);
	}
	cout << ans << endl;
}