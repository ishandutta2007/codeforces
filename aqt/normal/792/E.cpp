
// Problem : E. Colored Balls
// Contest : Educational Codeforces Round 18
// URL : https://codeforces.com/contest/792/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505];
const int M = 50000;

long long solve(long long x){
	long long tot = 0;
	for(int j = 1; j<=N; j++){
		int c = (arr[j]+x)/(x+1);
		if(x*c <= arr[j]){
			tot += c;
		}
		else{
			return LLONG_MAX>>2;
		}
	}
	return tot;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	long long ans = LLONG_MAX>>2;
	for(int i = 1; i<=M; i++){
		ans = min(ans, solve(i));
	}
	for(int i = 1; i<=M; i++){
		if(arr[1]/i != 0){
			ans = min(ans, solve(arr[1]/i));
		}
		if(arr[1]/i > 1){
			ans = min(ans, solve(arr[1]/i-1));
		}
	}
	cout << ans << "\n";
}