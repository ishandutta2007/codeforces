
// Problem : A. Multiples of Length
// Contest : Codeforces - Codeforces Round #666 (Div. 1)
// URL : https://codeforces.com/contest/1396/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}	
	if(N == 1){
		cout << 1 << " " << 1 << "\n";
		cout << -arr[1] << "\n";
		cout << 1 << " " << 1 << "\n";
		cout << 0 << "\n";
		cout << 1 << " " << 1 << "\n";
		cout << 0 << "\n";
		return 0;
	}
	cout << 1 << " " << 1 << "\n";
	cout << -arr[1] << "\n";
	arr[1] = 0;
	cout << 2 << " " << N << "\n";
	for(int i = 2; i<=N; i++){
		long long m = arr[i]%N;
		arr[i] += m*(N-1);
		cout << m*(N-1) << " ";
	}
	cout << "\n";
	cout << 1 << " " << N << "\n";
	for(int i = 1; i<=N; i++){
		cout << -arr[i] << " ";
	}
	cout << "\n";
}