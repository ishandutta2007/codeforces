#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vi a(n), b(n), c(m), d(m);
	rep(i,0,n) cin >> a[i] >> b[i];
	rep(i,0,m) cin >> c[i] >> d[i];

	vi ls(1e6+10, 0);

	rep(i,0,n) rep(j,0,m){
		int x = c[j] - a[i];
		int y = d[j] - b[i];
		if(min(x, y) >= 0)
			ls[x] = max(ls[x], y+1);
	}
	rrep(i,0,1e6+9)
		ls[i] = max(ls[i], ls[i+1]);
	int ans = 3e6;
	rep(i,0,1e6+10) ans = min(ans, i + ls[i]);
	cout << ans << endl;
}