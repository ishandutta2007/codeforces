
// Problem : F. The Neutral Zone
// Contest : Codeforces - Codeforces Round #502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1017/problem/F
// Memory Limit : 16 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
unsigned int A, B, C, D;
unsigned int ans;
bitset<100000005> sieve;

int getidx(int n){
	if(n%6 == 1){
		return n/6*2;
	}
	else if(n%6 == 5){
		return (n+1)/6*2-1;
	}
	else{
		return 0;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> A >> B >> C >> D;
	for(int i = 2; i<=N; i++){
		if(i == 2 || i == 3 || (getidx(i) && !sieve[getidx(i)])){
			//cout << i << "\n";
			for(long long j = 1LL*i*i; j<=N; j += i){
				if(getidx(j)){
					sieve[getidx(j)] = 1;
				}
			}
			unsigned int val = A*i*i*i + B*i*i + C*i + D;
			for(long long j = i; j<=N; j *= i){
				ans += N/j * val;
				//cout << j << " " << N/j << " " << val << "\n";
				//cout << ans << "\n";
			}
		}
	}
	cout << ans << "\n";
}