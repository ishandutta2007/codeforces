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
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n);
	trav(x, a) cin >> x;
	k = min(k, m-1);
	vi res(m);
	rep(i,0,m) res[i] = max(a[i], a[n-(m-i)]);
	int ans = 0;
	rep(j,0,k+1){
		int cur = 1e9;
		rep(i,j,m-(k-j))
			cur = min(cur, res[i]);
		ans = max(ans, cur);
	}
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}