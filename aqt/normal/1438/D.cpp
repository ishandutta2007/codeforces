
// Problem : D. Powerful Ksenia
// Contest : Codeforces - Codeforces Round #682 (Div. 2)
// URL : https://codeforces.com/contest/1438/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
	}
	for(int i = 3; i<=N; i+=2){
		arr[1] ^= arr[i];
		arr[1] ^= arr[i-1];
		arr[i] = arr[i-1] = arr[1];
	}
	for(int i = 3; i<=N; i+=2){
		arr[i] = arr[i-1] = arr[1];
	}
	if(arr[N] != arr[1]){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << (N-1)/2*2 << "\n";
	for(int i = 3; i<=N; i+=2){
		cout << 1 << " " << i-1 << " " << i << "\n";
	}
	for(int i = 3; i<=N; i+=2){
		cout << 1 << " " << i-1 << " " << i << "\n";
	}
}