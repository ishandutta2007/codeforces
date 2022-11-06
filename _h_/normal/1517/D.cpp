#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int inf = 1e9;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m, k;
	cin >> n >> m >> k;

	if(k % 2){
		rep(i,0,n){
			rep(j,0,m) cout << -1 << " ";
			cout << endl;
		}
		return 0;
	}

	vector<vi> ver(n, vi(m-1)), hor(n-1, vi(m));
	trav(v, ver) trav(x, v) cin >> x;
	trav(v, hor) trav(x, v) cin >> x;
	
	vector<vi> ans(n, vi(m, 0));

	rep(_,0,k/2){
		vector<vi> nxt(n, vi(m, inf));
		rep(i,0,n) rep(j,1,m){
			nxt[i][j] = min(nxt[i][j], ans[i][j-1] + ver[i][j-1]);
			nxt[i][j-1] = min(nxt[i][j-1], ans[i][j] + ver[i][j-1]);
		}
		rep(i,1,n) rep(j,0,m){
			nxt[i][j] = min(nxt[i][j], ans[i-1][j] + hor[i-1][j]);
			nxt[i-1][j] = min(nxt[i-1][j], ans[i][j] + hor[i-1][j]);
		}
		ans = nxt;
	}
	trav(v, ans){
		trav(x, v) cout << 2*x << " ";
		cout << endl;
	}
}