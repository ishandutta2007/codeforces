
// Problem : D. Winter is here
// Contest : Codeforces - Codeforces Round #428 (Div. 2)
// URL : https://codeforces.com/problemset/problem/839/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const int M = 1000000;
int arr[200005];
bool pr[1000005];
int sieve[1000005];
int cnt[1000005];
long long pows[200005];
const long long MOD = 1e9+7;

long long mult(long long a, long long b){
	return a*b%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(sieve, sieve+1+M, 1);
	for(int i = 2; i<=M; i++){
		if(pr[i]){
			continue;
		}
		for(int j = i; j<=M; j+=i){
			pr[j] = 1;
			if(sieve[j]){
				sieve[j] = mult(sieve[j], MOD-1);
			}
		}
		for(long long j = 1LL*i*i; j<=M; j+=1LL*i*i){
			sieve[j] = 0;
		}
	}
	cin >> N;
	pows[0] = 1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		pows[i] = mult(pows[i-1], 2);
		const int S = sqrt(arr[i]);
		for(int k = 2; k<=S; k++){
			if(arr[i]%k == 0){
				cnt[k]++;
				if(arr[i]/k != k){
					cnt[arr[i]/k]++;
				}
			}
		}
		cnt[arr[i]]++;
	}
	long long ans = 0;
	for(int n = 2; n<=M; n++){
		for(int c = 1; n*c<=M; c++){
			ans += mult(mult(cnt[c*n], pows[max(0, cnt[c*n]-1)]), mult(sieve[c], n));
			ans %= MOD;
		}
	}
	cout << ans;
}