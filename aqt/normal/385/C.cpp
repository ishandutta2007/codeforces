
// Problem : C. Bear and Prime Numbers
// Contest : Codeforces - Codeforces Round #226 (Div. 2)
// URL : https://codeforces.com/contest/385/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M = 10000000;
int sieve[10000005];
long long pre[10000005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 2; i<=M; i++){
		if(!sieve[i]){
			for(int j = i; j<=M; j+=i){
				sieve[j] = i;
			}
		}
	}
	for(int i= 1; i<=N; i++){
		int n;
		cin >> n;
		//cout << n << " " << sieve[n] << endl;
		while(sieve[n]){
			int p = sieve[n];
			pre[p]++;
			while(n%p == 0){
				n /= p;
			}
		}		
	}
	partial_sum(pre, pre+1+M, pre);
	int Q;
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		r = min(r, M);
		l = min(l, M);
		cout << pre[r] - pre[l-1] << "\n";
	}
}