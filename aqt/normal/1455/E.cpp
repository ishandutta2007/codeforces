
// Problem : E. Four Points
// Contest : Codeforces - Educational Codeforces Round 99 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1455/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
long long x[4], y[4];
vector<int> perm = {0, 1, 2, 3};
vector<long long> tx, ty;

long long calc(long long v){
	tx = {x[perm[0]], x[perm[1]], x[perm[2]]-v, x[perm[3]]-v};
	ty = {y[perm[0]], y[perm[1]]-v, y[perm[2]], y[perm[3]]-v};
	nth_element(tx.begin(), tx.begin()+1, tx.end());
	nth_element(ty.begin(), ty.begin()+1, ty.end());
	long long ret = 0;
	for(auto n : tx){
		ret += abs(n - tx[1]);
	}
	for(auto n : ty){
		ret += abs(n - ty[1]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		for(int k = 0; k<4; k++){
			cin >> x[k] >> y[k];
		}
		long long ans = LLONG_MAX/2;
		perm = {0, 1, 2, 3};
		do{
			long long l = 0, r = 10000000000LL;
			while(l <= r){
				long long mid = l+r>>1;
				long long m0 = calc(mid);
				long long m1 = calc(mid+1);
				ans = min(ans, m0);
				ans = min(ans, m1);
				if(m0 <= m1){
					r = mid - 1;
				}
				else{
					l = mid + 1;
				}
			}
		}
		while(next_permutation(perm.begin(), perm.end()));
		cout << ans << "\n";
	}
}