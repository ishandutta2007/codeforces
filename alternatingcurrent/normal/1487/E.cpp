#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmin(int a, int b){
	return (a < b) ? a : b;
}

int n[5];
int cost[5][150150];
vector<int> v_pre[5][150150];
int dp[5][150150];
int p[150150];
int rp[150150];
int cur;
bool cmp(int a, int b){
	return dp[cur-1][a] < dp[cur-1][b];
}

int main(){
	ios::sync_with_stdio(false); 
	rep(i, 150000) p[i] = i;
	rep(i, 4) cin >> n[i];
	rep(i, 4){
		rep(j, n[i]) cin >> cost[i][j];
	}
	rep(i, 3){
		int m;
		cin >> m;
		rep(j, m){
			int a, b;
			cin >> a >> b;
			a--, b--;
			v_pre[i+1][b].push_back(a); 
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	rep(i, n[0]) dp[0][i] = cost[0][i];
	for(cur = 1; cur < 4; cur++){
		rep(i, 150000) p[i] = i;
		sort(p, p + n[cur - 1], cmp);
		rep(i, n[cur - 1]) rp[p[i]] = i;
		rep(j, n[cur]) sort(v_pre[cur][j].begin(), v_pre[cur][j].end(), cmp);
		rep(j, n[cur]){
			int pos = 0;
			while(pos < (int)v_pre[cur][j].size() && dp[cur - 1][v_pre[cur][j][pos]] == dp[cur - 1][p[pos]]) pos++;
//			cout << j << ": " << pos << " " << p[pos] << " ";
			if(pos < n[cur - 1]) dp[cur][j] = qmin(dp[cur - 1][p[pos]] + cost[cur][j], 0x3f3f3f3f);
//			cout << dp[cur][j] << endl;
		}
//		cout << endl;
	}
	int ans = 0x3f3f3f3f;
	rep(i, n[3]) ans = qmin(ans, dp[3][i]);
	if(ans >= 0x3f3f3f3f) cout << "-1" << endl;
	else cout << ans << endl;
	return 0;
}