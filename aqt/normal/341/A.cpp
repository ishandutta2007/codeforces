
// Problem : A. Tourist Problem
// Contest : Codeforces - Codeforces Round #198 (Div. 1)
// URL : https://codeforces.com/contest/341/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long arr[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	long long tot = 0;
	long long pre = 0;
	for(int i = 1; i<=N; i++){
		tot += arr[i] * (i-1) - pre;
		pre += arr[i];
	}
	tot *= 2;
	tot += pre;
	long long g = __gcd(tot, 1LL*N);
	tot /= g;
	N /= g;
	cout << tot << " " << N;
}