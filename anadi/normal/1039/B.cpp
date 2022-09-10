#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n;
int d;
LL curPos = MX;

bool ask(LL a, LL b){
	printf("%lld %lld\n", a, b);
	fflush(stdout);
	
	char s[10];
	scanf("%s", s);

	if(s[0] == 'N')
		return false;
	if(s[0] == 'Y'){
		if(a == b)
			exit(0);
		return true;
	}
	
	assert(false);
}

LL val(LL a, LL b){
	return rand()%(b - a + 1) + a;
}

int main(){
	srand(*new int);
	scanf("%lld %d", &n, &d);
	
	LL p = 1, k = n;
	while(k - p > 5 * d){
		LL m = (p + k) / 2LL;
		if(ask(p, m)){
			k = min(m + d, n);
			p = max(p - d, 1LL);
		}
		else{
			p = max(m + 1 - d, 1LL);
			k = min(k + d, n);
		}
	}
	
	while(true){
		LL x = val(p, k);
		ask(x, x);
		
		p = max(p - d, 1LL);
		k = min(k + d, n);
		
		while(k - p > 5 * d){
			LL m = (p + k) / 2LL;
			if(ask(p, m)){
				k = min(m + d, n);
				p = max(p - d, 1LL);
			}
			else{
				p = max(m - d, 1LL);
				k = min(k + d, n);
			}
		}
	}

	return 0;
}