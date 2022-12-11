
// Problem : E. Are You Fired?
// Contest : Codeforces - Codeforces Round #645 (Div. 2)
// URL : https://codeforces.com/contest/1358/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[500005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int K = (N+1)/2;
	long long tot = 0;
	for(int i = 1; i<=K; i++){
		cin >> arr[i];
		tot += arr[i];
	}
	int X;
	cin >> X;
	for(int i = K+1; i<=N; i++){
		arr[i] = X;
		tot += X;
	}
	long long mn = 0;
	long long pre = 0;
	for(int l = N; l>=K; l--){
		if(tot + mn > 0){
			cout << l << "\n";
			return 0;
		}
		long long s = -arr[N-l+1]+X;
		pre += s;
		mn = min(mn, pre);
		tot -= X;
	}
	cout << -1;
}