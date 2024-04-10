
// Problem : E. Cow and Treats
// Contest : Codeforces Round #621 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1307/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> dp[2][2][4];
int arr[5005];
pair<int, int> cow[5005];
int brr[5005];
int lft[5005], rht[5005];
int MOD = 1e9+7;
pair<int, int> pre, now;

inline void f(){
	if(pre.first > now.first){
		now = pre;
	}
	else if(pre.first == now.first){
		now.second += pre.second;
		if(now.second >= MOD){
			now.second -= MOD;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}	
	for(int i = 1; i<=M; i++){
		cin >> cow[i].first >> cow[i].second;
		brr[i] = cow[i].second;
		cow[i].second = i;
	}
	for(int i = 1; i<=M; i++){
		int cnt = brr[i];
		for(int j = 1; j<=N && cnt; j++){
			if(arr[j] == cow[i].first){
				cnt--;
			}			
			if(!cnt){
				lft[i] = j;
				break;
			}
		}
		cnt = brr[i];
		for(int j = N; j && cnt; j--){
			if(arr[j] == cow[i].first){
				cnt--;
			}
			if(!cnt){
				rht[i] = j;
				break;
			}
		}
		if(!lft[i]){
			lft[i] = N+1;
			rht[i] = -1;
		}
	}
	sort(cow+1, cow+1+M);
	pair<long long, long long> ans = make_pair(0, 0);
	for(int k =0; k<=N; k++){
		dp[0][0][0] = make_pair(0, 1);
		dp[0][1][0] = make_pair(0, 0);
		for(int m = 1; m<4; m++){
			dp[0][0][m] = dp[0][1][m] = make_pair(0, 0);
		}
		if(!k){
			swap(dp[0][0][0], dp[0][1][0]);
		}
		for(int ii = 1; ii<=M; ii++){
			int i = ii&1;
			for(int m = 0; m<4; m++){
				dp[i][0][m] = dp[i][1][m] = make_pair(0, 0);
			}
			if(cow[ii].first != cow[ii-1].first){
				for(int b = 0; b<2; b++){
					for(int m = 0; m<4; m++){
						pre = dp[i^1][b][m];
						now = dp[i][b][0];
						f();
						dp[i][b][0] = now;
					}
				}
			}
			else{
				for(int b = 0; b<2; b++){
					for(int m = 0; m<4; m++){
						pre = dp[i^1][b][m];
						now = dp[i][b][m];
						f();
						dp[i][b][m] = now;
					}
				}				
			}
			int idx = cow[ii].second;
			for(int b = 1; b>=0; b--){
				for(int m = 3; m; m--){
					now = dp[i][b][m];				
					if(m&1){ 
						if(b && lft[idx] == k){
							pre = dp[i][b][m^1];
							pre.first++;
							f();
							pre = dp[i][b^1][m^1];
							pre.first++;
							f();
						}
						else if(lft[idx] < k){
							pre = dp[i][b][m^1];
							pre.first++;
							f();
						}
					}
					if((m&2) && rht[idx] > k){
						pre = dp[i][b][m^2];
						pre.first++;
						f();
					}
					dp[i][b][m] = now;					
				}
			}
		}
		now = ans;
		for(int m = 0; m<4; m++){
			pre = dp[M&1][1][m];
			f();
		}
		ans = now;
	}
	cout << ans.first << " " << ans.second << "\n";
}