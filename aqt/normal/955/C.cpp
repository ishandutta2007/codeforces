
// Problem : C. Sad powers
// Contest : Codeforces - Codeforces Round #471 (Div. 2)
// URL : https://codeforces.com/contest/955/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int lim[60];

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret *= ret;
	if(e&1){
		ret *= b;
	}
	return ret;
}

long long solve(long long n){
	if(n == 0){
		return 0;
	}
	long long ret = 0;
	for(int i= 2; i<60; i++){
		int idx = -1;
		for(int p : pr){
			if(i%p == 0){
				if(i%(p*p) == 0){
					idx = 0;
				}
				idx *= -1;
			}
		}
		//cout << i << " " << (floor((pow(n, 1.0/i)))) << "\n";
		if(idx){
			long long l = 1, r = lim[i], f =0;
			while(l <= r){
				long long mid = l+r>>1;
				long long temp = qikpow(mid, i);
				if(temp > n){
					r = mid - 1;
				}
				else{
					l = mid + 1;
					f = mid;
				}
			}
			ret += idx*(f-1);
		}
	}
	//cout << n << " " << ret+1 << "\n";
	return ret + 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int Q;
	cin >> Q;
	for(int i = 2; i<60; i++){
		lim[i] = pow(2000000000000000000LL, 1.0/i);
	}
	while(Q--){
		long long l, r;
		cin >> l >> r;
		cout << solve(r) - solve(l-1) << "\n";
	}
}