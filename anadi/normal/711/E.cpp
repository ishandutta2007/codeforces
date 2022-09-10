#include <bits/stdc++.h>

using namespace std;

typedef double d;
typedef long long int LL;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PDD pair <d, d>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const LL MX = 1e6 + 3LL;

LL szybkie(LL a, LL b){
	if(b == 0)
		return 1;
	LL x = szybkie(a, b / 2LL);
	if(b%2 == 0)
		return (x * x)%MX;
	return (((x * x)%MX) * a)%MX;
}

LL RevMod(LL a){
	return szybkie(a, MX - 2);
}

LL n, k;

LL _do(LL a){
	LL r = 1LL;
	while(a--)
		r *= 2LL;
	return r;
}

int main(){
	scanf("%I64d %I64d", &n, &k);
	
	if(n <= 60 && _do(n) < k){
		puts("1 1");
		return 0;
	}
	
	LL dol = szybkie(2, n);
	LL up = 1LL;
	LL x = dol;
	dol = szybkie(dol, k - 1);
	LL min = 0LL;
	for(LL i = 2LL; i < k; i *= 2LL)
		min += (k - 1) / i;

	min = szybkie(2, min);
	dol *= RevMod(min);
	dol %= MX;
	
	k--;
	
	if(k > x)
		up = 0LL;
	else
		while(k--){
			up *= --x;
			up %= MX;
		}
	
	up *= RevMod(min);
	up %= MX;
	up = dol - up;
	up += MX;
	up %= MX;

	printf("%I64d %I64d\n", up, dol);
	return 0;
}