
// Problem : B. Maximums
// Contest : Codeforces Global Round 7
// URL : https://codeforces.com/contest/1326/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int mx = 0;
	for(int i =1 ; i<=N; i++){
		int n;
		cin >> n;
		cout << n + mx << " ";
		mx = max(n + mx, mx);
	}
}