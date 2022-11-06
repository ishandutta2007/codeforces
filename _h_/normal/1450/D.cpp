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
	int n;
	cin >> n;
	vi as(n);
	trav(x, as) cin >> x;
	set<int> pos;
	pos.insert(-1);
	pos.insert(n);
	vi perm(n);
	iota(all(perm), 0);
	sort(all(perm), [&](int i, int j){return as[i] < as[j];});
	vi upto(n+1,0);
	trav(i, perm){
		auto it = pos.upper_bound(i);
		int r = *it;
		int l = *prev(it);
		pos.insert(i);
		upto[as[i]] = max(upto[as[i]], r-l-1);	
	}
	vi bc(n+2);
	rep(x,1,n+1){ // we know that x stops appearing for k > upto[x]
		// so k > upto[x], n-k+1 >= x are bad
		// k <= n+1-x 
		int fr = upto[x], to = n-x+1;
		if(fr >= to) continue;
		++bc[fr];
		--bc[to];
	}
	int sum = bc[0];
	string ans(n, '0');
	rep(k,1,n+1){
		ans[k-1] = sum > 0 ? '0' : '1';	
		sum += bc[k];
	}
	cout << ans << endl;
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