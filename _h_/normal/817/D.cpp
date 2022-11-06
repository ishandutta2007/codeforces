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
	ll ans = 0;
	rep(_,0,2){
		vi p(n);
		rep(i,0,n) p[i] = i;
		sort(all(p), [&](int x, int y){
			return as[x] < as[y];
		});
		vi ls(n), rs(n);
		rep(i,0,n) ls[i] = i+1;
		rep(i,0,n) rs[i] = i;
		trav(i, p){
			int l = i ? ls[i-1] : 0;
			int r = i+1<n ? rs[i+1] : i+1;
			ls[l] = ls[r-1] = l;
			rs[l] = rs[r-1] = r;
			ans += (ll)as[i]*(i-l+1)*(r-i);
		}
		trav(x, as) x *= -1;
	}
	cout << ans << endl;
}