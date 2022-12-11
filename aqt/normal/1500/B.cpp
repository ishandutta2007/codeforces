
// Problem : B. Two chandeliers
// Contest : Codeforces - Codeforces Round #707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1500/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long K;
int arr[500005];
int parr[1000005];
int brr[500005];
int pbrr[1000005];
long long rrr[1000005];

pair<long long, long long> extgcd(long long a, long long b){
	if(!b){
		return make_pair(1, 0);
	}
	pair<long long, long long> val = extgcd(b, a%b);
	return make_pair(val.second, val.first - a / b * val.second);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	fill(parr+1, parr+1+1000000, -1);
	fill(pbrr+1, pbrr+1+1000000, -1);
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		parr[arr[i]] = i;
	}
	for(int i = 0; i < M; i++){
		cin >> brr[i];
		pbrr[brr[i]] = i;
	}
	vector<int> cand;
	const long long G = __gcd(N, M);
	const long long L = 1LL * N * M / G;	
	pair<long long, long long> sol = extgcd(N, M);
	for(int k = 1; k <= 1000000; k++){
		if(parr[k] != -1 && pbrr[k] != -1 && (pbrr[k] - parr[k]) % G == 0){
			long long rem = sol.first * N * ((pbrr[k] - parr[k]) / G) + parr[k];
			rem %= L;
			if(rem < 0){
				rem += L;
			}
			rrr[k] = rem;
			cand.emplace_back(k);
		}
	}
	long long l = 1, r = 1e18, ans = 0;
	while(l <= r){
		long long mid = (l + r) / 2;
		long long tot = 0;
		const long long quo = mid / L, rmid = mid % L;
		for(auto k : cand){
			tot += quo;
			tot += rrr[k] < rmid;
		}
		if(mid - tot < K){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			ans = mid;
		}
	}
	cout << ans;
}