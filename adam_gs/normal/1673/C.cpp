#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7, LIM=4e4+7;
ll dp[LIM];
bool pal(int x) {
	int p=x, a=0;
	while(p) {
		a*=10;
		a+=p%10;
		p/=10;
	}
	return a==x;
}
void solve() {
	int n;
	cin >> n;
	cout << dp[n] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	dp[0]=1;
	rep(i, LIM-1) {
		if(pal(i+1)) {
			rep(j, LIM) if(j-i-1>=0) dp[j]=(dp[j]+dp[j-i-1])%MOD;
		}
	}
	int _=1;
	cin >> _;
	while(_--) solve();
}