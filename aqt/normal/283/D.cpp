
// Problem : D. Cows and Cool Sequences
// Contest : Codeforces - Codeforces Round #174 (Div. 1)
// URL : https://codeforces.com/contest/283/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[5005];
long long arr[5005];
long long pows2[5005];
long long odd[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		dp[i] = i-1;
		odd[i] = arr[i];
		while(odd[i] % 2 == 0){
			odd[i] /= 2;
			pows2[i]++;
		}
	}
	for(int i = 2; i <= N; i++){
		if((2 * arr[i - 1]) % arr[i] == 0 && (2 * arr[i - 1] / arr[i]) % 2 != arr[i] % 2){
			dp[i] = dp[i - 1];
		}
		for(int j = 1; j < i - 1; j++){
			bool cond = 1;
			cond &= (odd[j] % odd[i] == 0);
			cond &= (pows2[i] - pows2[j] == i - j) 
			|| (pows2[i] <= i - j - 1);
			if(cond){
				dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
		}
	}
	int ans = N;
	for(int i = 1; i <= N; i++){
		//cout << dp[i] << "\n";
		ans = min(ans, dp[i] + N - i);
	}
	cout << ans;
}