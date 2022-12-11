
// Problem : D. Tiles for Bathroom
// Contest : Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1500/problem/D
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1505][1505];
vector<pair<int, int>> dp[1505][1505];
vector<pair<int, int>> v;
int pre[1505];
int tkn[1505 * 1505], c;
set<int> st;

void combine(int i, int j){
	if(!i || !j){
		return;
	}
	for(auto p : dp[i][j]){
		v.emplace_back(p.first, p.second + 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			v.emplace_back(arr[i][j], 0);
			combine(i-1, j);
			combine(i, j-1);
			combine(i-1, j-1);
			sort(v.begin(), v.end(), [](auto p, auto q){
				return p.second < q.second;
			});
			c++;
			for(auto p : v){
				if(tkn[p.first] != c){
					//cout << p.first << " " << p.second << "\n";
					dp[i][j].push_back(p);
					tkn[p.first] = c;
				}				
				if(dp[i][j].size() == K + 1){
					break;
				}
			}
			v.clear();
			st.clear();
			if(dp[i][j].size() >= K + 1){
				//cout << i << " " << j << " " << dp[i][j][K].second << "\n";
				pre[min({i, j, dp[i][j][K].second})]++;
			}
			else{
				//cout << " " << i << " " << j << " " << min(i, j) << "\n";
				pre[min(i, j)]++;
			}
		}
	}
	for(int t = N; t; t--){
		pre[t] += pre[t + 1];
	}
	for(int t = 1; t <= N; t++){
		cout << pre[t] << "\n";
	}
}