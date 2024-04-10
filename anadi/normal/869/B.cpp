#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

LL a, b;

LL RS(LL a, LL b){
	if(b == 0)
		return 0LL;
	LL x = RS(a, b / 2LL);
	if(b & 1)
		return (2LL * x + a)%10;
	return (2LL * x)%10;
}

int main(){
	scanf("%lld %lld", &a, &b);
	if(b - a >= 10){
		puts("0");
		return 0;
	}
	
	if(b == a){
		puts("1");
		return 0;
	}
	
	LL cur = 1LL;
	while(a < b){
		++a;
		cur = RS(cur, a);
		cur %= 10LL;
	}
	
	printf("%lld\n", cur);
	return 0;
}