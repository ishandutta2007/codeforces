
// Problem : D. Portals
// Contest : Codeforces - Codeforces Round #608 (Div. 2)
// URL : https://codeforces.com/contest/1271/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int dp[5005][10005];
int mx[5005];
int a[5005], b[5005], c[5005];
vector<int> v[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		cin >> a[i] >> b[i] >> c[i];
		mx[i] = i;
		v[i].push_back(0);
	}
	memset(dp, -1, sizeof dp);
	dp[0][K] = 0;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		mx[b] = max(mx[b], a);
	}
	for(int i = 1; i<=N; i++){
		v[mx[i]].push_back(c[i]);
		sort(v[i].begin()+1, v[i].end(), greater<int>());
		partial_sum(v[i].begin(), v[i].end(), v[i].begin());
		for(int k = 0; k<=5000; k++){
			for(int j = 0; j<v[i].size(); j++){
				int lst = k+j-b[i];
				if(lst >= a[i] && dp[i-1][lst] != -1){
					dp[i][k] = max(dp[i][k], dp[i-1][lst] + v[i][j]);
					//cout << i << " " << k << " " << dp[i][k] << "\n";
					//cout << j << " " << v[i][j] << "\n";
				}
			}
		}
	}
	cout << *max_element(dp[N], dp[N]+5001) << "\n";
}