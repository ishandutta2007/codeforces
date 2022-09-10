#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 1e7 + 8;
const LL MOD = (1LL << 32) - 1;
const LL INF = LL(5e18) + 9LL;

LL n, l, r;
LL x, y, z;
LL in[N];

void solve(){
	scanf("%lld %lld %lld", &n, &l, &r);
	scanf("%lld %lld %lld", &x, &y, &z);
	scanf("%lld %lld", &in[1], &in[2]);

	for(int i = 3; i <= n; ++i)
		in[i] = (in[i - 1] * y + in[i - 2] * x + z)&MOD;
	for(int i = 1; i <= n; ++i){
		in[i] = in[i]%(r - l + 1) + l;
//		printf("%lld ", in[i]);
	}
	
	LL best = in[1], res = INF;
	for(int i = 2; i <= n; ++i){
		if(best < in[i])
			res = min(res, best * in[i]);
		best = min(best, in[i]);
	}
	
	best = in[n];
	for(int i = n - 1; i >= 1; --i){
		if(in[i] < best)
			res = min(res, best * in[i]);
		best = max(best, in[i]);
	}
	
	if(res == INF)
		puts("IMPOSSIBLE");
	else
		printf("%lld\n", res);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}