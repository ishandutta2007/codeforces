
// Problem : E. Hiking
// Contest : Codeforces - Codeforces Round #277.5 (Div. 2)
// URL : https://codeforces.com/contest/489/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[1005], val[1005];
long double dp[1005];
int par[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i] >> val[i];
	}
	long double l = 0, r = 1e6, ans = 0;
	for(int t = 0; t<60; t++){
		long double mid = (l+r)/2;
		for(int i = 1; i<=N; i++){
			long double ret = 1e12;
			for(int j = 0; j<i; j++){
				ret = min(ret, sqrt(abs(K-arr[i]+arr[j])) + dp[j]);
			}
			dp[i] = ret - mid * val[i];
		}
		if(dp[N] >= 0){
			l = mid;
		}
		else{
			r = mid;
			ans = mid;			
		}
	}
	for(int i = 1; i<=N; i++){
		long double ret = 1e12;
		for(int j = 0; j<i; j++){
			if(ret > sqrt(abs(K-arr[i]+arr[j])) + dp[j]){
				par[i] = j;
			}
			ret = min(ret, sqrt(abs(K-arr[i]+arr[j])) + dp[j]);
		}
		dp[i] = ret - ans * val[i];
	}
	vector<int> out;
	int c = N;
	while(c){
		out.push_back(c);
		c = par[c];
	}
	sort(out.begin(), out.end());
	for(int n : out){
		cout << n << " ";
	}
}