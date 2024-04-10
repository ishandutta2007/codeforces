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

const int inf = 1e7;

void mineq(int &a, int b){
	a = min(a, b);
}

void solve(){
	string s;
	cin >> s;
	vi dp(4);
	rep(i,0,sz(s)){
		int ok = 0;
		rep(j,1,3) if(i-j < 0 || (s[i-j] != s[i])) ok += 1<<(j-1);
		vi nxt(4, inf);
		rep(t,0,4) mineq( nxt[((t<<1)^1)&3], dp[t] + 1);
		rep(t,0,4) if( (t | ok) == 3 ){
			mineq(nxt[(t<<1)&3], dp[t]);
		}
		dp = nxt;
	}
	int ans = inf;
	rep(i,0,4) mineq(ans, dp[i]);
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