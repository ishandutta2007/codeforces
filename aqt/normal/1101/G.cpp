
// Problem : G. (Zero XOR Subset)-less
// Contest : Educational Codeforces Round 58 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1101/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int basis[40];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i] ^= arr[i-1];
	}
	int sz = 0;
	if(arr[N] == 0){
		cout << -1 << "\n";
		return 0;
	}
	for(int i = N; i; i--){
		for(int b = 30; b>=0; b--){
			if(arr[i]>>b&1){
				if(!basis[b]){
					basis[b] = arr[i];
					sz++;
				}
				arr[i] ^= basis[b];
			}
		}
	}
	cout << sz << "\n";
}