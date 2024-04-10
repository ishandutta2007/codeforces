#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qmin(ll a, ll b){
	return (a < b) ? a : b;
}

int n;
ll init, inc, rest;
int cnt[1010];
ll cost[1010];
ll dp[1010][10010];
multiset<ll> dp_set[1010];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> init >> inc >> rest;
	rep(i, n) cin >> cnt[i];
	rep(i, n) cin >> cost[i];
	memset(dp, 0xc0, sizeof(dp));
	dp[0][0] = init;
	rep(i, n){
		rep(j, 10001){
			if(dp[i][j] >= 0) dp_set[i].insert(dp[i][j] + j * cost[i]);
			if(dp_set[i].empty()) break;
			dp[i+1][j] = *(--dp_set[i].end()) - j * cost[i];
			if(j >= cnt[i]){
				multiset<ll>::iterator it = dp_set[i].find(dp[i][j - cnt[i]] + (j - cnt[i]) * cost[i]); 
				dp_set[i].erase(it);
			}
		}
		rep(j, 10001){
			if(dp[i+1][j] < 0) continue;
			dp[i+1][j] += rest;
			dp[i+1][j] = qmin(dp[i + 1][j], init + inc * j);
		}
	}
	rep(j, 10001) if(dp[n][j] < 0){
		cout << j-1 << endl;
		break;
	}
	return 0;
}