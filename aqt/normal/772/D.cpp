
// Problem : D. Varying Kibibits
// Contest : Codeforces - VK Cup 2017 - Round 2
// URL : https://codeforces.com/problemset/problem/772/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int M = 1000000;
int N;
long long cnt[1000005];
long long sqrsum[1000005];
long long sum[1000005];
long long osum[1000005];
long long tot[1000005];
int crnt[1000005];
const long long MOD = 1e9+7;
vector<int> v[1000005];
long long pows[1000005];
int stor[1000005];

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b %MOD;
}

long long sub(long long a, long long b){
	a = add(a, -b);
	return a < 0 ? a+MOD : a;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<M; i++){
		crnt[i] = i;
	}
	pows[0] = 1;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		cnt[n]++;
		osum[n] = add(osum[n], mult(sum[n], n));
		sum[n] = add(sum[n], n);
		sqrsum[n] = add(1LL*n*n, sqrsum[n]);
		pows[i] = mult(pows[i-1], 2);
	}
	for(int e = 0; e<=5; e++){
		for(int n = M-1; n; n--){
			if(crnt[n]%10 != 9){
				int t = n + pow(10, e);
				osum[n] = add(osum[n], osum[t]);
				osum[n] = add(osum[n], mult(sum[t], sum[n]));
				sum[n] = add(sum[n], sum[t]);
				sqrsum[n] = add(sqrsum[n], sqrsum[t]);
				cnt[n] = add(cnt[n], cnt[t]);		
			}
			v[n].emplace_back((crnt[n]%10));
			crnt[n]/=10;
		}
	}
	long long out = 0;
	for(int n = 1; n<M; n++){
		tot[n] = add(tot[n], mult(osum[n], pows[cnt[n]-1]));
		tot[n] = add(tot[n], mult(sqrsum[n], pows[cnt[n]-1]));
	}
	for(int m = 0; m<64; m++){
		for(int b = 0; b<6; b++){
			if(m>>b&1){
				stor[m] += pow(10, b);
			}
		}		
	}
	for(int n = 1; n<M; n++){
		int mask = 0;
		for(int b = 0; b<6; b++){
			if(v[n][b] != 9){
				mask |= (1<<b);
			}
		}
		for(int m = mask; m; m = (m-1)&mask){
			int c = n + stor[m];
			if(__builtin_popcount(m)&1){
				tot[n] = sub(tot[n], tot[c]);
			}
			else{
				tot[n] = add(tot[n], tot[c]);
			}
		}
		out ^= 1LL*tot[n]*n;
	}
	cout << out;
}