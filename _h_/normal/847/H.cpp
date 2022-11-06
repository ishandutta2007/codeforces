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
	vi as(n);
	trav(x, as) cin >> x;
	vector<ll> pre(n+1), suf(n+1);
	vi c1(n), c2(n);
	int pr = -1;
	rep(i,0,n){
		int nx = max(as[i], pr+1);
		c1[i] = nx-as[i];
		pre[i+1] = pre[i] + c1[i];
		pr = nx;
	}
	pr = -1;
	rrep(i,0,n){
		int nx = max(as[i], pr+1);
		c2[i] = nx-as[i];
		suf[i] = suf[i+1] + c2[i];
		pr = nx;
	}
	ll ans = 1e18;
	rep(i,0,n){
		ans = min(ans, pre[i]+suf[i+1]+max(c1[i],c2[i]));
	}
	cout << ans << endl;
}