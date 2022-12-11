
// Problem : F. Foo Fighters
// Contest : Codeforces - Codeforces Global Round 3
// URL : https://codeforces.com/problemset/problem/1148/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v[100];
long long val[300005];
long long msk[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long tot = 0;
	for(int i = 1; i <= N; i++){
		cin >> val[i] >> msk[i];
		assert(msk[i]);
		//cout << __builtin_ctzll(msk[i]) << "\n";
		v[__builtin_ctzll(msk[i])].emplace_back(i);
		tot += val[i];
	}
	long long ans = 0;
	for(long long b = 62; b >= 0; b--){
		long long s = 0;
		for(int n : v[b]){
			//cout << " " << n << " " << val[n] << "\n";
			s += val[n];
		}
		//cout << b << " " << s << " " << tot << "\n";
		if(((s < 0) && (tot < 0)) || ((s > 0) && (tot > 0))){
			ans |= (1LL << b);
			for(int n = 1; n <= N; n++){
				if(msk[n]>>b&1){
					val[n] *= -1;
				}	
			}
		}
	}
	cout << ans;
}