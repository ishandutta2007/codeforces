
// Problem : E. The Unbearable Lightness of Weights
// Contest : Codeforces - Technocup 2019 - Elimination Round 3
// URL : https://codeforces.com/contest/1032/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[105];
long long dp[105][10005];
long long tmp[10005];
int fre[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	dp[0][0] = 1;
	set<int> st;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		fre[arr[i]]++;
		st.insert(arr[i]);
	}
	if(st.size() <= 2){
		cout << N << "\n";
		return 0;
	}
	for(int i = 1; i<=N; i++){
		for(int j = i; j; j--){
			for(int w = arr[i]; w<=10000; w++){
				dp[j][w] += dp[j-1][w-arr[i]];
				//dp[j][w] = min(dp[j][w], 2);
			}
		}
	}
	int ans = 1;
	for(int i = 1; i<=100; i++){
		fill(tmp, tmp+10001, 0);
		tmp[0] = 1;
		for(int k = 1; k<=fre[i]; k++){
			for(int j = 10000; j >= i; j--){
				tmp[j] += tmp[j-i];
			}
		}
		for(int k = 1; k<=fre[i]; k++){
			//cout << i << " " << k << " " << dp[k][i*k] << "\n";
			if(dp[k][i*k] == tmp[i*k]){
				ans = max(ans, k);
			}
		}
	}
	cout << ans << "\n";
}