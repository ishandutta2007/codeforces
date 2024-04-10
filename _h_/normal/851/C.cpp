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
	if(n >= 40){
		cout << 0 << endl;
		return 0;
	}
	vector<vi> xy(n, vi(5));
	trav(v, xy) trav(x, v) cin >> x;
	vi ans;
	rep(a,0,n){
		rep(b,0,n) if(b != a) rep(c,0,b){
			int sum = 0;
			rep(i,0,5) sum += (xy[b][i]-xy[a][i])*(xy[c][i]-xy[a][i]);
			if(sum > 0) goto done;
		}
		ans.push_back(a);
		done: ;
	}

	cout << sz(ans) << endl;
	trav(x, ans) cout << x+1 << endl;
}