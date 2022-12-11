
// Problem : D. XOR-gun
// Contest : Codeforces - Technocup 2021 - Elimination Round 2
// URL : https://codeforces.com/contest/1415/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i] ^= arr[i-1];
	}
	if(N > 100){
		cout << 1;
		return 0;
	}
	int ans = 2*N;
	for(int i = 1; i<=N; i++){
		for(int j = i; j<=N; j++){
			for(int k = j+1; k<=N; k++){
				if((arr[i-1]^arr[j]) > (arr[k]^arr[j])){
					ans = min(k - i - 1, ans);
				}
			}
		}
	}
	if(ans == 2*N){
		ans = -1;
	}
	cout << ans;
}