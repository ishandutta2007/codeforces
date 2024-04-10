
// Problem : D. Same GCDs
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long A, M;
		cin >> A >> M;
		long long L = A, R = A+M-1;
		long long ans = 0;
		long long G = __gcd(A, M);
		long long K = M/G;
		vector<long long> v;
		for(long long i = 2; i<=sqrt(K); i++){
			if(K%i == 0){
				v.emplace_back(i);
				while(K % i == 0){
					K /= i;
				}
			}
		}
		if(K > 1){
			v.emplace_back(K);
		}
		for(int msk = 0; msk < (1<<v.size()); msk++){
			long long P = G;
			for(int k = 0; k<v.size(); k++){
				if((1<<k)&msk){
					P *= v[k];
				}
			}
			if(__builtin_popcount(msk)%2 == 1){
				ans -= R/P - (L-1)/P;
			}
			else{
				ans += R/P - (L-1)/P;
			}
		}
		cout << ans << "\n";
	}
}