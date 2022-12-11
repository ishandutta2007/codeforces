// Problem : D. Tournament Construction
// Contest : Codeforces - Codeforces Round #432 (Div. 1, based on IndiaHacks Final Round 2017)
// URL : https://codeforces.com/contest/850/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[70];
int dp[70][2500][70];
int out[70][70];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	bool contain0 = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		contain0 |= !arr[i];
	}
	sort(arr+1, arr+1+N);
	for(int i = 0; i<=61; i++){
		for(int k = i*(i-1)/2; k<2500; k++){
			for(int l = 0; l<=N; l++){
				dp[i][k][arr[l]] = -1;
			}
		}
	}
	dp[contain0][0][0] = 1;
	for(int i = contain0; i<=61; i++){
		//cout << i << " " << i*(i-1)/2 << "\n";
		for(int k = i*(i-1)/2; k<2500; k++){
			for(int l = 0; l<=N; l++){
				if(dp[i][k][arr[l]] != -1){
					if(l){
						dp[i+1][k+arr[l]][arr[l]] = arr[l];
					}
					if(l != N){
						dp[i+1][k+arr[l+1]][arr[l+1]] = arr[l];
					}
				}
			}
		}
	}
	int ans = 0;
	vector<pair<int, int>> v;
	for(int i = 1; !ans; i++){
		if(dp[i][i*(i-1)/2][arr[N]] != -1){
			ans = i;
			int d1 = i*(i-1)/2, d2 = arr[N];
			for(int k = i; k; k--){
				//cout << k << " " << d1 << " " << d2 << "\n";
				v.push_back({d2, k});
				int temp = d2;
				d2 = dp[k][d1][d2];
				d1 -= temp;
			}
		}
	}
	cout << ans << "\n";
	sort(v.begin(), v.end());
	while(v.size()){
		int i = 0;
		for(int j = 1; j<v.size(); j++){
			//cout << v[i].first << "\n";
			if(v[i].first){
				//cout << v[i].first << " " << v[j].second << "\n";
				v[i].first--;
				out[v[i].second][v[j].second] = 1;
			}
			else{
				//cout << v[i].second << " " << v[i].first << "\n";
				out[v[j].second][v[i].second] = 1;
				v[j].first--;
			}
		}
		v.erase(v.begin());
		sort(v.begin(), v.end());
	}
	for(int i = 1; i<=ans; i++){
		for(int j = 1; j<=ans; j++){
			cout << out[i][j];
		}
		cout << "\n";
	}
}