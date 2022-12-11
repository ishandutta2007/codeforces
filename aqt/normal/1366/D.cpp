
// Problem : D. Two Divisors
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const int M = 1e7;
int lst[M+5];
int cur[M+5];
int sz[M+5];
int arr[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	fill(cur+1, cur+1+M, 1);
	for(int i = 2; i<=M; i++){
		if(!sz[i]){
			for(int j = i; j<=M; j+=i){
				sz[j]++;
				lst[j] = i;
				cur[j] *= i;
			}
		}
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(sz[arr[i]] < 2){
			cout << -1 << " ";
		}
		else{
			cout << cur[arr[i]]/lst[arr[i]] << " ";
		}
	}
	cout << "\n";
	for(int i = 1; i<=N; i++){
		if(sz[arr[i]] < 2){
			cout << -1 << " ";
		}
		else{
			cout << lst[arr[i]] << " ";
		}
	}
}