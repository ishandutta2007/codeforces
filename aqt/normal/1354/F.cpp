
// Problem : F. Summoning Minions
// Contest : Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1354/problem/F
// Memory Limit : 512 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, K;
long long dp[80][80];
int par[80][80];
int ord[80];
pair<int, int> arr[80];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> K;
		for(int i = 1; i<=N; i++){
			ord[i] = i;
			cin >> arr[i].first >> arr[i].second;
		}
		sort(ord+1, ord+1+N, [](int x, int y){
			return arr[x].second < arr[y].second;
		});
		for(int i = 0; i<=N; i++){
			for(int j = 0; j<=K; j++){
				dp[i][j] = LLONG_MIN/2;
				par[i][j] = 0;
			}
		}
		dp[0][0] = 0;
		for(int i = 1; i<=N; i++){
			for(int j = 0; j<=K; j++){
				if(j && dp[i][j] < dp[i-1][j-1] + arr[ord[i]].first + arr[ord[i]].second * (j-1)){
					dp[i][j] = dp[i-1][j-1] + arr[ord[i]].first + arr[ord[i]].second * (j-1);
					par[i][j] = 1;
				}
				if(dp[i][j] < dp[i-1][j] + arr[ord[i]].second * (K-1)){
					dp[i][j] = dp[i-1][j] + arr[ord[i]].second * (K-1);
					par[i][j] = 0;
				}
			}
		}
		vector<int> v1, v2;
		int crnt = K;
		for(int i = N; i; i--){
			if(par[i][crnt]){
				crnt--;
				v1.push_back(ord[i]);
			}
			else{
				v2.push_back(ord[i]);
			}
		}
		reverse(v1.begin(), v1.end());
		cout << v1.size() + 2*v2.size() << "\n";
		for(int i = 0; i<K-1; i++){
			cout << v1[i] << " ";
		}
		for(int i = 0; i<v2.size(); i++){
			cout << v2[i] << " " << -v2[i] << " ";
		}
		cout << v1.back() << "\n";
	}
}