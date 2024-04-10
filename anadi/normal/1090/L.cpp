#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL t, n, a, b, k;
LL cnta, cntb;

bool ok(LL c){
	LL need = c * k;
	if(need > cnta + cntb)
		return false;
	
	need -= min(a, c) * ((n + 1) / 2);
	need -= min(b, c) * (n / 2);
	return need <= 0;
}

int main(){
	scanf("%lld %lld %lld %lld %lld", &t, &n, &a, &b, &k);
	if(k > n){
		puts("0");
		exit(0);
	}
	
	cnta = 1LL * (n + 1) / 2 * a;
	cntb = 1LL * n / 2 * b;
	
	if(n >= k + k || (a >= b && n >= k + k - 1)){
		printf("%lld\n", min((cnta + cntb) / k, 1LL * t));
		return 0;
	}
	
	LL p = 0, k = t;
	while(p < k){
		LL m = (p + k + 1) / 2;
		if(ok(m))
			p = m;
		else
			k = m - 1;
	}

	printf("%lld\n", p);
	return 0;
}