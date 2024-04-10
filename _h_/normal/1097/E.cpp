#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

vi ts(1000);

void solve(){
	int n;
	cin >> n;

	vi as(n);
	trav(x, as) cin >> x;

	vector<vi> ans;

	for(; n; n = sz(as)){
		int k = lower_bound(all(ts),n) - ts.begin();

		vi pek(n), dp(k+1, 1e6), org(k+1);
		dp[0] = 0;
		rep(i,0,n){
			int j = lower_bound(all(dp), as[i]) - dp.begin();
			pek[i] = org[j-1];
			if(j == k+1){
				vi ls;
				vector<bool> rm(n, false);
				rep(_,0,k+1){
					ls.push_back(as[i]);
					rm[i] = true;
					i = pek[i];
				}
				reverse(all(ls));
				ans.push_back(ls);
				vi bs;
				rep(i,0,n) if(!rm[i]) bs.push_back(as[i]);
				as = bs;
				goto foo;
			} else if(dp[j] > as[i]){
				dp[j] = as[i];
				org[j] = i;
			}
		}
		if(true){
			vector<vi> ls(k);
			rep(i,0,n){
				int j = 0;
				while(!ls[j].empty() && as[i]>ls[j].back()) ++j;
				ls[j].push_back(as[i]);
			}
			trav(v, ls) if(sz(v)) ans.push_back(v);
			break;
		}
		foo: ;
	}
	cout << sz(ans) << endl;
	trav(v, ans){
		cout << sz(v);
		trav(x, v) cout << ' ' << x;
		cout << endl;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ts[1] = 2;
	rep(k,2,1000) ts[k] = k+1 + ts[k-1];

	int t;
	cin >> t;
	rep(_,0,t) solve();
}