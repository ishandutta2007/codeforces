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

const int mx = 1e6+1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vi ispr(mx,1);
	rep(p,2,mx) if(ispr[p])
		for(int k = p+p; k < mx; k += p)
			ispr[k] = 0;


	int n;
	ll x, y;
	cin >> n >> x >> y;
	vi cnt(mx);
	rep(_,0,n){
		int a;
		cin >> a;
		++cnt[a];
	}
	vi pre0(3*mx+1);
	vector<ll> pre1(3*mx+1);
	rep(i,0,mx) pre0[i+1] = pre0[i] + cnt[i];
	rep(i,0,mx) pre1[i+1] = pre1[i] + ll(cnt[i])*i;
	rep(i,mx+1,3*mx+1) pre0[i] = pre0[mx], pre1[i] = pre1[mx];
	ll ans = 1e16;
	int num = (x-1)/y;
	rep(p,2,mx) if(ispr[p]){
		ll cur = 0;
		for(int lo = 1, hi = p; lo < mx; lo += p, hi += p){
			int mi = max(lo, hi-num);
			cur += x*(pre0[mi]-pre0[lo]);
			int c = pre0[hi]-pre0[mi];
			ll d = pre1[hi]-pre1[mi];
			cur += y*(ll(c)*hi - d);
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}