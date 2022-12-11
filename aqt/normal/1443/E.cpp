
// Problem : E. Long Permutation
// Contest : Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL : https://codeforces.com/problemset/problem/1443/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int suf[20];
long long fact[20];

void build(int msk, int idx, int lim, long long k){
	if(idx > lim){
		return;
	}
	//cout << " " << idx << " " << lim << " " << msk << " " << k << "\n";
	long long tot = 0;
	for(int a = 1; a<=lim; a++){
		if(msk>>a&1){
			continue;
		}
		if(tot + fact[lim - idx] >= k){
			suf[idx] = a;
			build(msk^(1<<a), idx+1, lim, k - tot);
			return;
		}
		else{
			tot += fact[lim - idx];
		}
	}
}

long long calc(int n){
	long long ret = 0;
	int cntr = 1;
	for(int i = max(1, N - 15 + 1); i <= n; i++){
		ret += suf[cntr++] + max(0, N - 15);
	}
	//cout << ret << "\n";
	if(n > max(0, N - 15)){
		ret += 1LL * (max(0, N - 15)) * (max(0, N - 15) + 1) /2;
		//cout << 1LL * (max(0, N - 15)) * (max(0, N - 15) + 1) /2 << "\n";
	}
	else{
		ret += 1LL * n * (n + 1) / 2;
	}
	//cout << n << " " << ret << "\n";
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	long long crnt = 1;
	fact[0] = 1;
	for(int i = 1; i <= 20; i++){
		fact[i] = fact[i-1] * i;
	}
	build(0, 1, min(N, 15), 1);
	for(int i = 1; i<=N; i++){
		//cout << suf[i] << "\n";
	}
	while(Q--){
		int cmd;
		cin >> cmd;
		if(cmd == 1){
			int r, l;
			cin >> l >> r;
			cout << calc(r) - calc(l - 1) << "\n";
		}
		else{
			long long x;
			cin >> x;
			crnt += x;
			build(0, 1, min(N, 15), crnt);	
		}	
	}
}