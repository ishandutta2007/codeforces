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
	cin >> n;
	vi a(n), b(n), c(n);
	trav(x, a) cin >> x;
	trav(x, b) cin >> x;
	trav(x, c) cin >> x;
	vi ans(n);
	ans[0] = a[0];
	rep(i,1,n-1){
		ans[i] = a[i] == ans[i-1] ? b[i] : a[i];
	}
	vi abc = {a[n-1], b[n-1], c[n-1]};
	trav(x, abc) if(x != ans[n-2] && x != ans[0]){
		ans[n-1] = x;
	}
	trav(x, ans) cout << x << " ";
	cout << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	rep(_,0,n) solve();
}