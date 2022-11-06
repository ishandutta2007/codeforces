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
	
	int n,k,m;
	cin >> n >> k >> m;
	vi ts(k);
	trav(t, ts) cin >> t;
	sort(all(ts));
	int ans = 0;
	int tot = 0;
	trav(t, ts) tot += t;

	rep(i,0,n+1){
		int c = m - i*tot;
		if(c < 0) break;
		int cur = (k+1)*i;
		rep(j,0,k) rep(_,0,n-i){
			if(c >= ts[j]){
				c -= ts[j];
				++cur;
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
}