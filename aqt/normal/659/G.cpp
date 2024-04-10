
// Problem : G. Fence Divercity
// Contest : Codeforces - Codeforces Round #346 (Div. 2)
// URL : https://codeforces.com/problemset/problem/659/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int h[1000005];
const long long MOD = 1e9+7;

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		cin >> h[i];
		h[i]--;
		ans = add(ans, h[i]);
	}
	long long pre = 0;
	for(int i = 1; i<=N; i++){
		ans = add(ans, mult(pre, min(h[i], h[i-1])));
		pre = mult(pre, min({h[i-1], h[i], h[i+1]}));
		pre = add(pre, min(h[i], h[i+1]));
	}
	cout <<ans;
}