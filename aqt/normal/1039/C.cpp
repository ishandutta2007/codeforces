
// Problem : C. Network Safety
// Contest : Codeforces Round #507 (Div. 1, based on Olympiad of Metropolises)
// URL : https://codeforces.com/contest/1039/problem/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
const long long MOD = 1e9+7;
int par[500005], sz[500005];
unordered_map<long long, vector<pair<int, int>>> mp;
long long val[500005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*(b%MOD)%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		return mult(ret, b);
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		par[i] = i;
		sz[i] = 1;
		cin >> val[i];
	}
	for(int i = 1; i<=M; i++){
		pair<int, int> p;
		cin >> p.first >> p.second;
		long long x = val[p.first] ^ val[p.second];
		mp[x].push_back({p.first, p.second});
	}
	long long ans = mult(qikpow(2, N), qikpow(2, K)-mp.size());
	for(auto p : mp){
		long long C = N;
		for(auto e : p.second){
			int pf = getrt(e.first), ps = getrt(e.second);
			if(ps != pf){
				C--;
				if(sz[pf] > sz[ps]){
					par[ps] = pf;
					sz[pf] += sz[ps];
				}
				else{
					par[pf] = ps;
					sz[ps] += sz[pf];
				}
			}
		}
		ans = add(ans, qikpow(2, C));
		for(auto e : p.second){
			par[e.first] = e.first;
			par[e.second] = e.second;
			sz[e.first] = sz[e.second] = 1;
		}
	}
	cout << ans << "\n";
}