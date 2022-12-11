
// Problem : D. The Best Vacation
// Contest : Codeforces - Codeforces Round #645 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1358/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
long long arr[400005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i+N] = arr[i];
	}
	N *= 2;
	long long ans = 0, rng = 0, sum = 0;
	for(int l = 1, r = 1; r<=N; r++){
		rng += arr[r];
		sum += arr[r]*(arr[r]+1)/2;
		while(rng - arr[l] > K){
			sum -= (arr[l]) *(arr[l]+1)/2;
			rng -= arr[l++];
		}
		long long temp = sum;
		if(rng > K){
			temp -= (rng-K)*(rng-K+1)/2;
		}
		//cout << l << " " << r << " " << temp << "\n";
		ans = max(ans, temp);
	}
	cout << ans;
}