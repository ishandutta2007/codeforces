#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n;

LL get(LL a){
	for(LL t = 1; t * t <= a; ++t)
		if(a%t == 0 && (a / t - t - 1)%2 == 0 && (a / t - t - 1) / 2 > 0)
			return t;
	return -1;
}

int main(){
	cin >> n;
	n--;
	
	LL ans = get(n);
	if(ans == -1)
		puts("NO");
	else
		printf("%lld %lld\n", ans, ((n / ans) - ans - 1) / 2);
	return 0;
}