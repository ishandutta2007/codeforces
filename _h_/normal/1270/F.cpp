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
	
	string s;
	cin >> s;
	ll ans = 0;
	
	int k = 100;
	rep(i,1,k){
		map<int,int> cnt;
		int cur = 0;
		++cnt[cur];
		trav(c,s){
			cur += (c=='1' ? i : 0) - 1;
			++cnt[cur];
		}
		trav(pa, cnt) ans += ll(pa.second)*(pa.second-1) / 2;
	}

	vi ls;
	ls.push_back(-1);
	int n = sz(s);
	rep(i,0,n) if(s[i] == '1') ls.push_back(i);
	ls.push_back(n);

	rep(i,1,sz(ls)-1){
		for(int j = i+1; k * (j-i) <= n - ls[i-1]-1 && j < sz(ls); ++j){
			int mx = ls[j] - ls[i-1] - 1, mn = ls[j-1] + 1 - ls[i],
				dif = min(ls[i] - ls[i-1], ls[j] - ls[j-1]);
			for(int l = k * (j-i); l <= mx; l += j-i){
				int cur = max(0, min( dif, min(l-mn+1, mx-l+1) ));
				ans += cur;
			}
		}
	}


	cout << ans << endl;
}