
// Problem : C. Lieges of Legendre
// Contest : Codeforces - Codeforces Round #334 (Div. 1)
// URL : https://codeforces.com/contest/603/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[100005];
map<int, int> dp;

int solve(int n){
	if(dp.count(n)){
		return dp[n];
	}
	if(n%2 == 1){
		return 0;
	}
	int k = solve(n/2);
	if(k == 0){
		return dp[n] = 1;
	}
	else if(k == 1){
		return dp[n] = 2;
	}
	else{
		return dp[n] = 1;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	if(K%2 == 0){
		int x = 0;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			if(arr[i] == 2){
				x ^= 2;
			}
			else if(arr[i] == 1){
				x ^= 1;
			}
			else{
				x ^= (arr[i]&1)^1;
			}
		}
		if(x){
			cout << "Kevin\n";
		}
		else{
			cout << "Nicky\n";
		}
		return 0;
	}
	//cout << 0 << " ";
	for(int i = 1; i<=10000; i++){
		if(i%2 == 1){
			if(dp[i-1] != 0){
				dp[i] = 0;
			}
			else{
				dp[i] = 1;
			}
		}
		else{
			if(dp[i-1] != 0 && dp[i/2] != 0){
				dp[i] = 0;
			}
			else if(dp[i-1] != 1 && dp[i/2] != 1){
				dp[i] = 1;
			}
			else{
				dp[i] = 2;
			}
		}
		//cout << dp[i] << " ";
	}
	int x = 0;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		x ^= solve(n);
	}
	cout << (x ? "Kevin" : "Nicky") << "\n";
}