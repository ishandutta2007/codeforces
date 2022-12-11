
// Problem : E. Game with Cards
// Contest : Codeforces - Codeforces Round #727 (Div. 2)
// URL : https://codeforces.com/contest/1539/problem/E
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int mn[2][100005];
int mx[2][100005];
int dp[2][100005];
bool pos[2][100005];
int nxt[2][100005];
int par[2][100005];
int arr[100005];
vector<int> mxdq[2];
vector<int> mndq[2];
int ans[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		for(int j = 0; j < 2; j ++){
			cin >> mn[j][i] >> mx[j][i];
		}
	}
	for(int i = N; i >= 0; i--){
		for(int j = 0; j < 2; j++){
			while(mxdq[j].size() && mn[j][mxdq[j].back()] <= mn[j][i]){
				mxdq[j].pop_back();
			}			
			mxdq[j].push_back(i);
			while(mndq[j].size() && mx[j][mndq[j].back()] >= mx[j][i]){
				mndq[j].pop_back();
			}
			mndq[j].push_back(i);
			int opt1 = N, opt2 = N;
			{
				int l = 0, r = mndq[j].size() - 1;
				//cout << mndq[j].size() << "\n";
				while(l <= r){
					int mid = l + r >> 1;
					if(mx[j][mndq[j][mid]] < arr[i]){
						//cout << j << " " << i << " " << mndq[j][mid] << " " << "here" << "\n";
						opt1 = mndq[j][mid] - 1;
						l = mid + 1;
					}
					else{
						r = mid - 1;
					}
				}
			}
			{
				int l = 0, r = mxdq[j].size() - 1;
				while(l <= r){
					int mid = l + r >> 1;
					if(mn[j][mxdq[j][mid]] > arr[i]){
						//cout << mxdq[j][mid] << " " << "there\n";
						opt2 = mxdq[j][mid] - 1;
						l = mid + 1;
					}
					else{
						r = mid - 1;
					}
				}
			}
			//cout << opt1 << " " << opt2 << "\n";
			nxt[j][i] = min(opt1, opt2);
		}
	}
	pos[0][0] = pos[1][0] = 1;
	dp[0][0] = nxt[1][0];
	dp[1][0] = nxt[0][0];
	//cout << nxt[0][0] << " " << nxt[1][0] << "\n";
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 2; j++){
			//cout << j << " " << i << " " << nxt[j][i] << "\n";
			if(nxt[j][i] < i){
				continue;
			}
			if(pos[j][i-1] && dp[j][i-1] >= i){
				dp[j][i] = dp[j][i-1];
				par[j][i] = 0;
				pos[j][i] = 1;
			}
			//cout << dp[j][i] << " " << dp[j][i-1] << "\n";
			if(pos[j^1][i-1] && nxt[j^1][i-1] >= i && dp[j][i] < nxt[j^1][i-1]){
				dp[j][i] = nxt[j^1][i-1];
				par[j][i] = 1;
				pos[j][i] = 1;
			}
			//cout << dp[j][i] << " " << dp[j][i-1] << "\n";
		}
	}
	for(int i = 1; i <= N; i++){
		//cout << dp[0][i] << " " << dp[1][i] << "\n";
	}
	if(dp[0][N] == N || dp[1][N] == N){
		cout << "Yes\n";
		int cur = (dp[0][N] == N ? 0 : 1);
		for(int i = N; i; i--){
			ans[i] = cur;
			cur ^= par[cur][i];
		}
		for(int i = 1; i <= N; i++){
			cout << ans[i] << " ";
		}
	}
	else{
		cout << "No\n";
	}
}