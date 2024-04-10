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

const int md = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	set<int> book;
	book.insert(0);

	map<int,int> dp;
	dp[0] = 1;

	rep(_,0,n){
		string s;
		int p;
		cin >> s >> p;
		if(s == "ADD"){
			auto it = book.upper_bound(p);
			--it;
			if(dp.count(*it)){
				dp[p] = dp[*it];
			}
			book.insert(p);
		} else {
			auto jt = book.find(p);
			auto it = jt;
			--it;
			ll res = dp[*it] + dp[p];
			if(res >= md) res -= md;
			dp.clear();
			dp[*it] = res;
			book.erase(jt);
		}
	}
	ll ans = 0;
	trav(pa, dp) ans += pa.second;
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}