
// Problem : F. Good Contest
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int lrng[55], rrng[55];
vector<int> v;
long long dp[55][105];
const long long MOD = 998244353;

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret *= ret;
	ret %= MOD;
	if(e&1){
		ret *= b;
		ret %= MOD;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long denom = 1;
	for(int i = N; i; i--){
		cin >> lrng[i] >> rrng[i];
		lrng[i]++, rrng[i]++;
		denom *= rrng[i] - lrng[i] + 1;
		denom %= MOD;
		v.push_back(lrng[i]);
		v.push_back(rrng[i]+1);
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	K = v.size();
	for(int k = 0; k<=K; k++){
		dp[0][k] = 1;
	}
	/*
	for(int i = 1; i<=N; i++){
		dp[i][0] = 1;
	}
	*/
	for(int i = 1; i<=N; i++){
		for(int k = 1; k<=K; k++){
			int l = 0, r = INT_MAX;
			dp[i][k] = dp[i][k-1];
			for(int j = i; j; j--){
				l = max(l, lrng[j]);
				r = min(r, rrng[j]+1);
				int lidx = lower_bound(v.begin(), v.end(), l) - v.begin();
				int ridx = lower_bound(v.begin(), v.end(), r) - v.begin();
				//cout << " " << lidx << " " << ridx << " " << k << endl;
				if(lidx <= k && k < ridx){
					long long cst = 1;
					//r-l+i-j+1 choose r-l;
					for(int c = v[k+1]-v[k]+i-j; c>v[k+1]-v[k]-1; c--){
						cst *= c;
						cst %= MOD;
					}
					for(int c = i-j+1; c; c--){
						cst *= qikpow(c, MOD-2);
						cst %= MOD;
					}
					dp[i][k] += dp[j-1][k-1] * cst;
					dp[i][k] %= MOD;
				}
				else{
					break;
				}
			}
			//cout << i << " " << k << " " << dp[i][k] << endl;
		}
	}
	//cout << dp[N][K] << endl;
	cout << dp[N][K] * qikpow(denom, MOD-2) % MOD << endl;
}