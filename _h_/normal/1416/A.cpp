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

void solve(){
	int n;
	cin >>n;
	vi a(n);
	trav(x, a) cin >> x;
	vector<vi> ls(n, {-1});
	rep(i,0,n) ls[a[i]-1].push_back(i);
	rep(i,0,n) ls[i].push_back(n);
	vi ans(n+1, n+1);
	rep(j,0,n){
		int k = 1;
		rep(i,1,sz(ls[j]))
			k = max(k, ls[j][i] - ls[j][i-1]);
		if(k <= n)
			ans[k] = min(ans[k], j+1);
	}
	rep(k,1,n) ans[k+1] = min(ans[k+1], ans[k]);
	rep(k,1,n+1){
		cout << (ans[k] == n+1 ? -1 : ans[k]) << " ";
	}
	cout << endl;
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