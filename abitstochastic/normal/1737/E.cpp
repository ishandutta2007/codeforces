#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int poww(long long a , int b){
	int tms = 1;
	while(b){
		if(b & 1)
			tms = tms * a % P;
		a = a * a % P; b >>= 1;}
	return tms;
}
int T , N , sum[1000003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; sum[N] = 1; sum[N + 1] = 0;
		for(int i = N - 1 ; i ; --i)
			sum[i] = ((sum[i + 1] - sum[min(N + 1 , 2 * i)] + 0ll + P) + sum[i + 1]) % P;
		int iv = poww(poww(2 , N) , P - 2) , val = 0;
		for(int i = 1 ; i < N ; ++i){
			int ans = (2ll * poww(2 , i / 2) * (sum[i] - sum[i + 1] + P) % P * iv % P);
			val = (val + ans) % P;
			cout << ans << '\n';
		}
		cout << (P + 1 - val) % P << '\n';
	}
	return 0;
}