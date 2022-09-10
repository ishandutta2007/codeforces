#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int N = 55;
const LL mod = 1e6 + 3;

LL n, c;

LL szybkie(LL a, LL b, LL mod){
	if(b == 0LL)
		return 1LL;
	LL x = szybkie(a, b / 2LL, mod);
	if(b & 1)
		return (((x * x)%mod) * a)%mod;
	return (x * x)%mod;
}

LL RevMod(LL a, LL b){
	return szybkie(a, b - 2, b);
}

LL sil(LL a){
	LL res = 1LL;
	for(LL i = 1LL; i <= a; ++i)
		res = (res * i) %mod;
	return res;
}

LL newton(LL a, LL b){
	LL down = (sil(b) * sil(a - b))%mod;
	LL res = (sil(a) * RevMod(down, mod))%mod;
	res--;
	res += mod;
	res %= mod;
	return res;
}

int main(){
	scanf("%I64d %I64d", &n, &c);
	printf("%I64d\n", newton(n + c, c));
	return 0;
}