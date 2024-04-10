
// Problem : D. Array Differentiation
// Contest : Codeforces - Codeforces Global Round 15
// URL : https://codeforces.com/contest/1552/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[10 + 5];
int sum[(1 << 10) + 5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		for(int k = 0; k < (1 << N); k++){
			sum[k] = 0;
			for(int t = 0; t < N; t++){
				if(k>>t&1){
					sum[k] += arr[t];
				}
			}
		}
		bool ans = 0;
		for(int i = 0; i < (1<< N); i++){
			for(int j = 0; j < (1 << N); j++){
				if((i&j) == 0 && (i != j)){
					if(sum[i] == sum[j]){
						ans = 1;
					}
				}
			}
		}
		if(ans){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}