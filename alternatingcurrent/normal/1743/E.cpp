#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
void chmin(ll &a, ll b){
	if(b < a){
		a = b;
	}
}

int p[2];
ll t[2];
int h, s;
ll dp[10010];
vector< pair<ll, int> > del;

int main(){
	ios::sync_with_stdio(false);
	
	cin >> p[0] >> t[0] >> p[1] >> t[1] >> h >> s;
	
	rep(i, 5000){
		del.emplace_back((i+1) * t[0], 0);
		del.emplace_back((i+1) * t[1], 1);
	}
	sort(del.begin(), del.end());
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	rep(d, h){
		int nsum = 0;
		rep(i, (int)del.size()){
			if(i < (int)del.size() && del[i+1].second != del[i].second && d + nsum + p[0] + p[1] - s <= 10000)
				chmin(dp[d+nsum+p[0]+p[1]-s], dp[d] + del[i+1].first);
			nsum += p[del[i].second] - s;
			if(d + nsum <= 10000)
				chmin(dp[d + nsum], dp[d] + del[i].first);
		}
	}
	
	ll ans = 0x3f3f3f3f3f3f3f3fll;
	for(int i = h; i <= 10000; ++i){
//		cout << i << ": " << dp[i] << endl;
		ans = min(ans, dp[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}