#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 1e6 + 7; int N , A[_] , B[_] , sum[_] , prm[_] , mu[_] , cprm , Q , psum[_]; bool nprm[_];

signed main(){
	ios::sync_with_stdio(0);
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = 1 ; i <= N ; ++i) cin >> B[i];
	for(int i = 2 ; i <= N ; ++i){
		if(!nprm[i]){prm[++cprm] = i; mu[i] = -1;}
		for(int j = 1 ; prm[j] * i <= N ; ++j){
			nprm[prm[j] * i] = 1; if(i % prm[j] == 0) break;
			mu[i * prm[j]] = -mu[i];
		}
	}
	mu[1] = 1;
	for(int i = 2 ; i <= N ; ++i) for(int j = i ; j <= N ; j += i) sum[j] += (A[i] - B[i]) * mu[j / i];
	int preans = 0;
	for(int i = 1 ; i <= N ; ++i){
		sum[i] += A[1] * mu[i]; preans += abs(sum[i]);
		switch(mu[i]){
		case 1:--psum[0]; psum[max(0ll , min(1000001ll , sum[i]))] += 2; break;
		case -1: --psum[0]; psum[max(0ll , min(1000001ll , -sum[i]))] += 2; break;
		}
	}
	for(int i = 1 ; i <= 1e6 ; ++i) psum[i] += psum[i - 1];
	for(int i = 1 ; i <= 1e6 ; ++i) psum[i] += psum[i - 1];
	for(cin >> Q ; Q ; --Q){int R; cin >> R; if(!R) cout << preans << '\n'; else cout << psum[R - 1] + preans << '\n';}
	return 0;
}