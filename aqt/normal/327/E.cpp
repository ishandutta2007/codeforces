//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")
// Problem : E. Axis Walking
// Contest : Codeforces - Codeforces Round #191 (Div. 2)
// URL : https://codeforces.com/problemset/problem/327/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

struct myphash{
	size_t operator()(const pair<long long, long long> &p) const{
		return p.first^(p.second<<16);
	}
};

long long N, K;
long long arr[30];
vector<long long> brr;
long long fact[30];
const long long MOD = 1e9+7;
cc_hash_table<pair<long long, long long>, long long, myphash> big[30][30];
cc_hash_table<pair<long long, long long>, vector<pair<long long, long long>>, myphash> lst;
map<long long, long long> mp[30];

long long solve(long long T){
	vector<long long> a, b;
	for(long long i = 0; i<N; i++){
		if(i >= 12){
			a.emplace_back(arr[i]);
		}
		else{
			b.emplace_back(arr[i]);
		}
	}
	for(int i = 0; i<=N; i++){
		mp[i].clear();
	}
	for(long long m = 0; m<1<<a.size(); m++){
		long long n = 0;
		for(long long i = 0; i<a.size(); i++){
			if(m>>i&1){
				n += a[i];
			}
		}
		mp[__builtin_popcount(m)][n]++;
		//mp[n] %= MOD;
	}
	long long ret = 0;
	for(long long m = 0; m<1<<b.size(); m++){
		long long n = 0;
		for(long long i = 0; i<b.size(); i++){
			if(m>>i&1){
				n += b[i];
			}
		}
		long long k = __builtin_popcount(m);
		for(long long i = 0; i<=a.size(); i++){
			ret += (mp[i][T-n] * ((fact[k+i] * fact[N-k-i]) % MOD)) % MOD;
			ret %= MOD;
		}
		ret %= MOD;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	fact[0] = 1;
	for(long long i = 0; i<N; i++){
		cin >> arr[i];
		fact[i+1] = fact[i] * (i+1) % MOD;
	}
	sort(arr, arr+N);
	cin >> K;
	for(long long k = 0; k<K; k++){
		long long n;
		cin >> n;
		brr.push_back(n);
	}
	sort(brr.begin(), brr.end());
	brr.erase(unique(brr.begin(), brr.end()), brr.end());
	K = brr.size();
	if(K == 0){
		cout << fact[N] << "\n";
		return 0;
	}
	else if(K == 1){
		cout << (fact[N] - solve(brr[0]) + MOD)%MOD << "\n";
		return 0;
	}
	vector<long long> a, b;
	long long tot = 0;
	for(long long i = 0; i<N; i++){
		if(i >= 12){
			a.push_back(arr[i]);
		}
		else{
			b.push_back(arr[i]);
		}
		tot += arr[i];
	}
	/*
	for(int m = 0; m<a.size(); m++){
		cout << a[m] << "\n";
	}
	cout << "\n";
	for(int m = 0; m<b.size(); m++){
		cout << b[m] << "\n";
	}
	*/
	random_shuffle(b.begin(), b.end());
	brr[1] = tot - brr[1];
	long long cnt = 0;
	for(long long m1 = 0; m1<1<<a.size(); m1++){
		for(long long m2 = (1<<a.size())-1-m1; 1; m2 = ((1<<a.size())-1-m1)&(m2-1)){
			pair<long long, long long> p = {0, 0};
			for(long long n = 0; n<a.size(); n++){
				if(m1>>n&1){
					p.first += a[n];
				}
				else if(m2>>n&1){
					p.second += a[n];
				}
			}
			//cout << p.first << " " << p.second << "\n";
			lst[p].emplace_back(__builtin_popcount(m1), __builtin_popcount(m2));
			big[__builtin_popcount(m1)][__builtin_popcount(m2)][p]++;
			//cout << big[__builtin_popcount(m1)][__builtin_popcount(m2)][p] << "\n";
			if(!m2){
				break;
			}
		}
	}
	for(auto &p : lst){
		sort(p.second.begin(), p.second.end());
		p.second.erase(unique(p.second.begin(), p.second.end()), p.second.end());
	}
	for(long long m1 = 0; m1<1<<b.size(); m1++){
		for(long long m2 = (1<<b.size())-1-m1; 1; m2 = ((1<<b.size())-1-m1)&(m2-1)){
			pair<long long, long long> p = {brr[0], brr[1]};
			for(long long n = 0; n<b.size(); n++){
				if(m1>>n&1){
					p.first -= b[n];
				}
				else if(m2>>n&1){
					p.second -= b[n];
				}
			}		
			//cout << p.first << " " << p.second << "\n";
			long long k1 = __builtin_popcount(m1), k2 = __builtin_popcount(m2);	
			auto v = lst[p];
			for(auto q : v){
				long long i = q.first, j = q.second;
				//cout << N-i-j-k1-k2 << "\n";
				//cout << fact[k1+i] << " " << fact[k2+j] << " " << fact[N-i-j-k1-k2] << " " << big[i][j][p] << "\n";
				//cout << big[i][j][p] << " " << i << " " << j << " " << p.first << " " << p.second << "\n";
				//assert((((fact[k1+i]*fact[k2+j])%MOD*fact[N-i-j-k1-k2])%MOD)%MOD >= 0);
				
				cnt += (big[i][j][p]*(((fact[k1+i]*fact[k2+j])%MOD*fact[N-i-j-k1-k2])%MOD))%MOD;
				//cout << cnt << "\n";
				cnt %= MOD;
			}
			if(!m2){
				break;
			}
		}
	}
	//cout << "here" << endl;
	//cout << fact[N] << " " << solve(brr[0]) << " " << solve(brr[1]) << " " << cnt << "\n";
	cout << (fact[N] - solve(brr[0]) - solve(brr[1]) + cnt + 10*MOD)%MOD;
}