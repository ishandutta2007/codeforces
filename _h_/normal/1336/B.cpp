#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (b);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

ll sq(int x){
	return ll(x)*x;
}

ll val(int a, int b, int c){
	return sq(a-b) + sq(b-c) + sq(a-c);
}

void solve(){
	int n[3];
	rep(i,0,3) cin >> n[i];
	vi w[3];
	rep(i,0,3){
		w[i].resize(n[i]);
		trav(x, w[i]) cin >> x;
		sort(all(w[i]));
	}
	ll ans = 3e18;
	rep(m,0,3) trav(c, w[m]){
		vi a, b;
		auto it = upper_bound(all(w[(m+1)%3]), c);
		if(it != w[(m+1)%3].end()) a.push_back(*it);
		if(it != w[(m+1)%3].begin()){
			--it;
			a.push_back(*it);
		}
		it = upper_bound(all(w[(m+2)%3]), c);
		if(it != w[(m+2)%3].end()) b.push_back(*it);
		if(it != w[(m+2)%3].begin()){
			--it;
			b.push_back(*it);
		}
		trav(x, a) trav(y, b) ans = min(ans, val(c, x, y));
	}
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}