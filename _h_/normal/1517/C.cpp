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

int ans[501][501];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi ps(n);
	trav(x, ps) cin >> x;

	rrep(l,1,n+1){
		rep(j,0,l) ans[n+1-l+j][j+1] = ps[j];	
		rep(j,0,l) if(ps[j] == n+1-l){
			ps.erase(ps.begin() + j);
			break;
		}
	}
	rep(i,1,n+1) rep(j,1,i+1) cout << ans[i][j] << (j==i ? '\n' : ' ');
}