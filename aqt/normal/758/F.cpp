
// Problem : F. Geometrical Progression
// Contest : Codeforces - Codeforces Round #392 (Div. 2)
// URL : https://codeforces.com/contest/758/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N, L, R;
	cin >> N >> L >> R;
	if(N == 1){
		cout << R-L+1;
	}
	else if(N == 2){
		cout << (R-L+1)*(R-L);
	}
	else{
		long long ans = 0;
		for(long long a = 1; a<=R; a++){
			long long powa = 1;
			bool f = 1;
			for(int i = 1; i<N; i++){
				powa *= a;
				if(powa > R){
					f = 0;
					break;
				}
			}
			if(!f){
				break;
			}
			for(long long b = 1; b<a; b++){
				if(__gcd(a, b) == 1){
					long long powb = 1;					
					bool flag = 1;
					for(int i = 1; i<N; i++){
						powb *= b;
						if(powb > R){
							flag = 0;
							break;
						}
					}
					if(!flag){
						break;
					}
					//cout << powa << " " << powb << "\n";
					ans += max(0LL, (R*powb/powa)/powb - (L - 1)/powb);
				}
			}
		}
		cout << 2*ans << "\n";
	}
}