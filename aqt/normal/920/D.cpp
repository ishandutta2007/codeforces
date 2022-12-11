
// Problem : D. Tanks
// Contest : Codeforces - Educational Codeforces Round 37 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/920/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, V;
int arr[5005];
bool dp[5005][5005];
int par[5005][5005];
bool tkn[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> V;
	int tot = 0;
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		tot += arr[i];
		for(int j = 0; j<K; j++){
			if(dp[i-1][j]){
				dp[i][j] = 1;
				dp[i][(j+arr[i])%K] = 1;
				par[i][(j+arr[i])%K] = i;
			}
		}
	}
	if(tot >= V && dp[N][V%K]){
		cout << "YES\n";
		int S = 1;
		int a = N, b = V%K;
		while(a){
			tkn[par[a][b]] = 1;
			if(par[a][b]){
				S = par[a][b];
			}
			//cout << " " << par[a][b] << " " << b << "\n";			
			b = ((b - arr[par[a][b]])%K + K)%K;
			a--;
		}
		/*
		for(int i = 1; i<=N; i++){
			if(tkn[i]){
				cout << i << "\n";
			}
		}
		*/
		int T = (S == 1 ? 2 : 1);
		if(!tkn[S]){
			cout << 1000000000 << " " << S << " " << T << "\n";
			arr[T] += arr[S];
			arr[S] = 0;
		}
		if(tkn[T]){
			cout << 1000000000 << " " << T << " " << S << "\n";
			arr[S] += arr[T];
			arr[T] = 0;
		}		
		for(int i = 1; i<=N; i++){
			if(i == S || i == T){
				continue;
			}
			if(!tkn[i]){
				cout << 1000000000 << " " << i << " " << T << "\n";
				arr[T] += arr[i];
				arr[i] = 0;
			}
			else{
				cout << 1000000000 << " " << i << " " << S << "\n";
				arr[S] += arr[i];
				arr[i] = 0;
			}
		}
		//cout << arr[S] << " " << V << "\n";
		/*
		if((arr[S]-V)/K){
			cout << (arr[S]-V)/K << " " << S << " " << T << "\n";
		}
		*/
		//cout << T << " " << S << "\n";
		if(arr[S] > V){
			cout << (arr[S]-V)/K << " " << S << " " << T << "\n";			
		}
		if(arr[S] < V){
			cout << (V-arr[S])/K << " " << T << " " << S << "\n";			
		}
	}
	else{
		cout << "NO";
	}
}