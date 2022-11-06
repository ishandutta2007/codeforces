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

const int inf = 1e9+1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<vi> ts(n+k, vi(m+k, inf));
	rep(_,0,q){
		int x,y,t;
		cin >> x >> y >> t;
		ts[x-1][y-1] = t;
	}
	vi ls;
	for(; k > 1; ++k, k /= 2)
		ls.push_back(k);
	reverse(all(ls));
	int pr = 1;
	trav(x, ls){
		rep(i,0,n) rep(j,0,m){
			ts[i][j] = max(ts[i][j], ts[i+x-pr][j]);
			ts[i][j] = max(ts[i][j], ts[i+x-pr][j+x-pr]);
			ts[i][j] = max(ts[i][j], ts[i][j+x-pr]);
		}
		pr = x;
	}
	int ans = inf;
	rep(i,0,n) rep(j,0,m) ans = min(ans, ts[i][j]);
	if(ans == inf) ans = -1;
	cout << ans << endl;
}