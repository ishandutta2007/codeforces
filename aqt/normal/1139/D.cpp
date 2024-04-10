
// Problem : D. Steps to One
// Contest : Codeforces - Codeforces Round #548 (Div. 2)
// URL : https://codeforces.com/contest/1139/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[100005];
const long long MOD = 1000000007;
vector<int> fact[100005], pr[100005];
bool sieve[100005];

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret = mult(ret, ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

int relativeprime(int x, int y){
	int ret = 0;
	for(int m = 0; m<1<<pr[x].size(); m++){
		int prod = 1;
		for(int k = 0; k<pr[x].size(); k++){
			if(m>>k&1){
				prod *= pr[x][k];
			}
		}
		if(__builtin_popcount(m)%2 == 0){
			ret += y/prod;
		}
		else{
			ret -= y/prod;
		}
		//cout << " " << y/prod << " " << prod << " " << ret << "\n";
	}
	//cout << x << " " << y << " " << ret << "\n";
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		for(int j = 2*i; j<=N; j+=i){
			fact[j].push_back(i);
		}
	}
	long long sum = 1;
	for(int i = 2; i<=N; i++){
		if(!sieve[i]){
			for(int j = i; j<=N; j+=i){
				sieve[j] = 1;
				pr[j].push_back(i);
			}
		}
		dp[i] = 1;
		for(int f : fact[i]){
			dp[i] = add(dp[i], mult(dp[f], relativeprime(i/f, N/f)));
		}
		dp[i] = mult(dp[i], qikpow(N - N/i, MOD-2));
		sum += dp[i];
	}
	cout << sum%MOD << "\n";
}