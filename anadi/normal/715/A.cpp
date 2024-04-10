#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define pb push_back

const int N = 1e5 + 7;

int n;

LL nwd(LL a, LL b){
	if(b == 0LL)
		return a;
	return nwd(b, a%b);
}

int main(){
	scanf("%d", &n);
	LL now = 2LL;
	for(int i = 2; i <= n + 1; ++i){
		LL t = 1LL * (LL)i * (LL)(i - 1LL) * (LL)i - (now / (LL)(i - 1));
		printf("%I64d\n", t);
		now = 1LL * (LL)i * (i - 1);
	}

	return 0;
}