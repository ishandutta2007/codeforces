
// Problem : C. Carrying Conundrum
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

/*
int rec(long long n, long long c){
	if(n == 0){
		//cout << c << "\n";
		return c == 0;
	}
	int ret = 0;
	for(int d = 0; d < 10; d++){
		for(int e = 0; e < 10; e++){
			if((d + e + c) % 10 == n % 10){
				//cout << d << " " << e << " " << n << " " << c << "\n";
				ret += rec(n / 10, (c/10) + (d + e + c%10) / 10 * 10);
			}
		}
	}
	return ret;
}
*/

long long pows[15];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	pows[0] = 1;
	for(int k = 1; k < 12; k++){
		pows[k] = pows[k-1] * 10;
	}
	while(T--){
		/*
		int N;
		cin >> N;
		cout << rec(N, 0) - 2 << "\n";
		*/
		int N;
		cin >> N;
		long long tot = 0;
		for(int msk = 0; msk < (1<<8); msk++){
			/*
			long long T = N;
			for(int k = 0; k < 9; k++){
				if(msk>>k&1){
					T -= pows[k+2];
				}
			}
			if(T < 0){
				continue;
			}
			*/
			long long M = N;
			//cout << M << " " << msk << "\n";
			long long temp = 1;
			for(int k = 0; k < 10; k++){
				long long cnt = 0;
				int c = 0;
				if(k >= 2){
					c = (msk >> (k-2))&1;
				}
				int needToCarry = (msk>>k)&1;
				//cout << " " << needToCarry*10+T%10 << "\n";
				for(int d = 0; d < 10; d++){
					for(int e = 0; e < 10; e++){
						
						if(d+e+c == needToCarry*10+M%10){
							cnt++;
						}
					}
				}
				//cout << cnt << "\n";
				temp *= cnt;
				M /= 10;
			}
			tot += temp;
			//cout << tot << "\n";
		}
		cout << tot-2 << "\n";
	}
}