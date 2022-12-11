
// Problem : D. Chaotic V.
// Contest : Codeforces Round #614 (Div. 1)
// URL : https://codeforces.com/contest/1292/problem/D
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M = 5000;
long long cnt[5005];
int sieve[5005];
int pcnt[5005];
int totcnt[5005][5005];
int temp[5005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		n += !n;
		cnt[n]++;
	}
	for(int i = 2; i<=M; i++){
		if(!sieve[i]){
			for(int j = i; j<=M; j+=i){
				sieve[j] = i;
				pcnt[j]++;
			}
		}
	}
	long long rtdis = 0;
	for(int n =1; n<=M; n++){
		for(int k = 2; k<=M; k++){
			if(pcnt[k] == 1){
				totcnt[n][sieve[k]] += n/k;
				rtdis += n/k*cnt[n];
			}
		}
	}
	long long ans = rtdis;
	for(int n = 1; n<=M; n++){
		int l = 1, r = M;
		long long sz = N;
		long long crnt = rtdis;
		fill(temp+1, temp+1+M, 0);
		for(int k = M; k; ){
			temp[k]++;
			if(temp[k] > totcnt[n][k]){
				while(totcnt[r][k] != totcnt[n][k]){
					sz -= cnt[r];
					r--;
				}
				while(totcnt[l][k] != totcnt[n][k]){
					sz -= cnt[l];
					l++;
				}
				k--;
				continue;
			}
			while(temp[k] > totcnt[l][k]){
				sz -= cnt[l];
				l++;
			}
			while(temp[k] > totcnt[r][k]){
				sz -= cnt[r];
				r--;
			}
			assert(l <= r);
			crnt -= sz;
			crnt += N-sz;
			ans = min(ans, crnt);
		}
	}
	cout << ans << endl;
}