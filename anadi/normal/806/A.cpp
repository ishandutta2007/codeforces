#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int inf = 1e9 + 7;

LL a, b, p, q;

bool ok(LL v){
	return p * v - a <= q * v - b;
}

LL bs(LL s, LL e){
	s = max((a + p - 1) / p, (b + q - 1) / q);
	while(s < e){
		LL m = (s + e) / 2LL;
		if(ok(m))
			e = m;
		else
			s = m + 1;
	}
	
	if(s == inf)
		return -1;
	return s * q - b;
}

void solve(){
	scanf("%lld %lld %lld %lld", &a, &b, &p, &q);
	if(p == q && a != b){
		puts("-1");
		return;
	}

	if(p == 0 && a != 0){
		puts("-1");
		return;
	}
	else if(p == 0 && a == 0){
		puts("0");
		return;
	}

	printf("%lld\n", bs(0, inf));
}

int main(){
	int quest;
	scanf("%d", &quest);
	while(quest--)
		solve();
	return 0;
}