#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i-->int(a);)
typedef long long ll;
typedef vector<ll> vi;
const ll md = 1e9+7;
int main(){
	string s;
	cin >> s >> s;
	ll n = s.size(), ans = 0;
	vector<vi> dp(n+1,vi(n+1)), sum(n+1,vi(n+1));
	vi pw(n+1), hs(n+1);
	pw[0] = 1;
	rep(i,0,n) pw[i+1] = pw[i]*12341891;
	rep(i,0,n) hs[i+1] = hs[i]+s[i]*pw[i];

	rep(b,0,n+1) rrep(a,0,b){
		if(a == 0) dp[a][b] = 1;
		else if(s[a] != '0'){
			int c = 2*a-b;
			dp[a][b] = sum[max(0,c+1)][a];
			bool gt = 0;
			if(c<0 || s[c] > s[a]) gt = 0;
			else if(s[a] > s[c]) gt = 1;
			else {
				int u = b-a+1,l = 1;
				while(l+1 < u){
					int m = (u+l)/2;
					if(hs[a+m]-hs[a] == (hs[c+m]-hs[c])*pw[a-c])
						l = m;
					else
						u = m;
				}
				if(l > 10 && s[c+l-10] != s[a+l-10]){
					rep(d,1,b-a){
						if(s[c+d]<s[a+d]) gt = 1;
						if(s[c+d]!=s[a+d]) break;
					}
				}
				else if(l == b-a || s[c+l] > s[a+l]) gt = 0;
				else gt = 1;
			}
			if(gt) dp[a][b] = (dp[a][b]+dp[c][a])%md;
		}
		sum[a][b] = (sum[a+1][b] + dp[a][b])%md;
		if(b == n) ans = (ans+dp[a][b])%md;
	}
	cout << ans << endl;
}