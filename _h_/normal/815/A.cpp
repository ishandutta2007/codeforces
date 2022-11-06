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
	
	int m,n;
	cin >> m >> n;
	vector<vi> g(m, vi(n));
	trav(v, g) trav(x, v) cin >> x;
	int mn = 500;
	trav(v, g) trav(x, v) mn = min(mn, x);

	vector<pair<bool,int>> ans;

	if(m > n)
		rep(i,1,n+1) rep(_,0,mn)
			ans.emplace_back(0, i);
	else
		rep(i,1,m+1) rep(_,0,mn)
			ans.emplace_back(1, i);
	trav(v, g) trav(x, v) x -= mn;
	int x, y;
	rep(i,0,m) rep(j,0,n) if(g[i][j]==0){
		x = i;
		y = j;
	}
	rep(i,0,m) rep(j,0,n) if(g[i][j] != g[i][y]+g[x][j]){
		cout << -1 << endl;
		return 0;
	}
	rep(i,0,m)
		rep(_,0,g[i][y])
			ans.emplace_back(1, i+1);
	rep(j,0,n)
		rep(_,0,g[x][j])
			ans.emplace_back(0, j+1);
	cout << sz(ans) << endl;
	trav(pa, ans){
		cout << (pa.first ? "row " : "col ");
		cout << pa.second << endl;
	}
}