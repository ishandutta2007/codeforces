
// Problem : A. Row GCD
// Contest : Codeforces - Codeforces Round #691 (Div. 1)
// URL : https://codeforces.com/contest/1458/problem/A
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	long long G = 0;
	for(int i = 2; i<=N; i++){
		G = __gcd(G, arr[i]-arr[1]);
	}
	while(M--){
		long long k;
		cin >> k;
		cout << __gcd(G, arr[1] + k) << " ";
	}
}