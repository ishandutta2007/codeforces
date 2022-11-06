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

void solve(){
	int n, k;
	cin >> n >> k;
	vi xs(n), ys(n);
	rep(i,0,n) cin >> xs[i] >> ys[i];
	rep(i,0,n){
		bool good = true;
		rep(j,0,n) if( abs(xs[j]-xs[i]) + abs(ys[j]-ys[i]) > k) good = false;
		if(good){
			cout << 1 << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}