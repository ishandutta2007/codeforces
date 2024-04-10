
// Problem : G. Mercenaries
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/G
// Memory Limit : 512 MB
// Time Limit : 7000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> arr[300005];
int cnt[300005];
long long fact[300005];
long long inv[300005];
int lft[300005], rht[300005];
long long combo[50][300005];
const long long MOD = 998244353;
bool tkn[300005];

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long sub(long long a, long long b){
	return ((a-b)%MOD+MOD)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

long long choose(long long n, long long r){
	if(n < r){
		return 0;
	}
	else if(r < 0){
		return 0;
	}
	return mult(fact[n], mult(inv[r], inv[n-r]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1; i<=N; i++){
		cin >> lft[i] >> rht[i];
		fact[i] = mult(fact[i-1], i);
		inv[i] = qikpow(fact[i], MOD-2);
		cnt[lft[i]]++;
		cnt[rht[i]+1]--;
	}
	for(int i = 1; i<=N; i++){
		cnt[i] += cnt[i-1];
	}
	for(int k = 0; k<=2*M; k++){
		for(int i = 1; i<=N; i++){
			combo[k][i] = choose(cnt[i]-k, i-k);
			combo[k][i] = add(combo[k][i-1], combo[k][i]);
		}
	}
	long long ans = 0;
	for(int i = 0; i<M; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int m = 0; m<1<<M; m++){
		int d = 0;
		int l = 1, r = N;
		for(int i = 0; i<M; i++){
			if(m>>i&1){
				if(!tkn[arr[i].first]){
					d++;
					tkn[arr[i].first] = 1;
					l = max(l, lft[arr[i].first]);
					r = min(r, rht[arr[i].first]);
				}
				if(!tkn[arr[i].second]){
					d++;
					tkn[arr[i].second] = 1;
					l = max(l, lft[arr[i].second]);
					r = min(r, rht[arr[i].second]);
				}
			}
		}
		if(l <= r){
			if(__builtin_popcount(m)&1){
				ans = sub(ans, sub(combo[d][r], combo[d][l-1]));
			}
			else{
				ans = add(ans, sub(combo[d][r], combo[d][l-1]));
			}
		}
		for(int i = 0; i<M; i++){
			tkn[arr[i].first] = tkn[arr[i].second] = 0;
		}
	}
	cout << ans;
}