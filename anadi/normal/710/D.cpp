#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back
#define mp make_pair
#define nd second
#define st first

const int N = 1e5 + 7;

LL gcd(LL a, LL b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

PLL Ext_Gcd(LL a, LL b){
	if(b == 0)
		return mp(1, 0);
	PLL result = Ext_Gcd(b, a%b);
	return mp(result.nd, result.st - (a/b)*result.nd);
}

LL a1, b1, a2, b2, L, R;

int main(){
	scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &a1, &b1, &a2, &b2, &L, &R);
	L = max(L, max(b1, b2));
	
	LL x = b2 - b1;
	LL y = gcd(a1, a2);
	if(x%y != 0){
		puts("0");
		return 0;
	}

	a1 /= y;
	a2 /= y;
	PLL res = Ext_Gcd(a1, a2);
	
	res.st *= x;
	res.nd *= x;
	res.st %= a2 * y;
	
	LL where = res.st * a1 + b1;

	LL diff = a1 * a2 * y;
	where = where + ((L - where) / diff) * diff;

	if(where < L)
		where += diff;

	LL r = 1;
	if(where > R){
		puts("0");
		return 0;
	}
	
	r += (R - where) / diff;
	printf("%I64d\n", r);
	return 0;
}