#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII  pair <int, int>

const int N = 1e6 + 7;
const int S = 1e8;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
vector <bool> V;
vector <bool> prime;
unsigned int res = 0;
unsigned int A, B, C, D;

unsigned int f(unsigned int p){
	return D + p * (C + p * (B + p * A));
}

unsigned int ile(int n, int p){
	int x = 1;
	unsigned int ret = 0;
	
	while(1LL * x * p <= n){
		x *= p;
		ret += n / x;
	}
	
	return ret;
}

void go(int from, int to){
	for(int i = 2; i * i <= to; ++i){
		if(!prime[i])
			continue;

		int st = max(i * i, from + i - from%i);
		if(from + i == st)
			st -= i;

		for(int j = st; j <= to; j += i)
			V[j - from] = true;
	}
	
	int st = from == 1 ? 1 : 0;
	for(int i = st; i < S; ++i){
		if(!V[i])
			res = res + ile(n, i + from) * f(i + from);
		V[i] = false;
	}
}

int main(){
	scanf("%d", &n);
	scanf("%u %u %u %u", &A, &B, &C, &D);
	
	prime.resize(20000, true);
	prime[0] = prime[1] = false;
	
	for(int i = 2; i * i < 20000; ++i)
		if(prime[i])
			for(int j = i * i; j < 20000; j += i)
				prime[j] = false;

	V.resize(S);
	go(1, S); go(S + 1, S + S); go(S + S + 1, 3 * S);
	printf("%u\n", res);
	return 0;
}