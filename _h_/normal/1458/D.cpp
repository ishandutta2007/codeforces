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
	string s;
	cin >> s;

	int n = sz(s);
	
	vi ls(n+1);
	int cur = 0;
	rep(i,0,n){
		cur += s[i] == '1' ? 1 : -1;		
		ls[i+1] = cur;
	}
	int mn = 0;
	trav(x, ls) mn = min(mn, x);
	trav(x, ls) x -= mn;
	int mx = 0;
	trav(x, ls) mx = max(mx, x);
	vi cnt(mx+1), trs(mx);
	trav(x, ls) ++cnt[x];
	rep(i,0,n) ++trs[min(ls[i], ls[i+1])];
	string ans;
	cur = ls[0];
	rep(i,0,n){
		--cnt[cur];
		int up = cur+1 <= mx ? cnt[cur+1] : 0;
		int down = cur-1 >= 0 ? cnt[cur-1] : 0;
		int ss = cur-1 >= 0 ? trs[cur-1] : 0;
		if(!up || (down && ss >= 2)){
			--cur;
			--trs[cur];
			ans.push_back('0');
		} else {
			--trs[cur];
			++cur;
			ans.push_back('1');
		}
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