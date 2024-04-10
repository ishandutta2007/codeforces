#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1 << 17;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
LL s[N + 9];
LL fib[N + 9];
LL A[N + 9], B[N + 9], C[N + 9];

LL fast(LL a, LL b){
	if(!b)
		return 1;

	LL x = fast(a, b / 2);
	if(b & 1)
		return (((1LL * x * x)%MX) * a)%MX;
	return (1LL * x * x)%MX;
}

void fwh(bool inv){
	for(int i = 0; i < 17; ++i)
		for(int j = 0; j < N; j += (1 << (i + 1))){
			for(int k = 0; k < (1 << i); ++k){
				C[j + k] = (C[j + k] + C[j + k + (1 << i)])%MX;
				C[j + k + (1 << i)] = (C[j + k] - 2 * C[j + k + (1 << i)])%MX;
			}
		}
	
	if(inv){
		LL rev = fast(N, MX - 2);
		for(int i = 0; i < N; ++i)
			C[i] = (1LL * C[i] * rev)%MX;
	}
}


int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a; scanf("%d", &a);
		s[a]++;
	}
	
	fib[0] = 0, fib[1] = 1;
	for(int i = 2; i < N; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2])%MX;
	
	for(int i = 0; i < N; ++i)
		B[i] = C[i] = s[i];
	
	for(int i = 0; i < N; ++i){
		int cur = i ^ (N - 1);
		for(int j = cur; true; j = (j - 1) & cur){
			A[i | j] = (A[i | j] + 1LL * s[i] * s[j])%MX;
			if(j == 0)	break;
		}
	}

	fwh(false);
	for(int i = 0; i < N; ++i)
		C[i] = (1LL * C[i] * C[i])%MX;
	fwh(true);
	
	for(int i = 0; i < N; ++i){
		A[i] = (1LL * A[i] * fib[i])%MX;
		B[i] = (1LL * B[i] * fib[i])%MX;
		C[i] = (1LL * C[i] * fib[i])%MX;		
	}
	
	for(int i = 0; i <= 16; ++i)
		for(int j = 0; j < N; ++j)
			if(!(j & (1 << i))){
				A[j] = (A[j] + A[j + (1 << i)])%MX;
				B[j] = (B[j] + B[j + (1 << i)])%MX;
				C[j] = (C[j] + C[j + (1 << i)])%MX;
			}
	
	for(int i = 0; i < N; ++i)
		A[i] = (((1LL * A[i] * B[i])%MX) * C[i])%MX;
	
	for(int i = 0; i <= 16; ++i)
		for(int j = 0; j < N; ++j)
			if(!(j & (1 << i)))
				A[j] = (A[j] - A[j + (1 << i)])%MX;	
	
	LL sum = 0;
	for(int i = 1; i < N; i *= 2)
		sum = (sum + A[i])%MX;
	printf("%lld\n", (sum + MX)%MX);
	return 0;
}