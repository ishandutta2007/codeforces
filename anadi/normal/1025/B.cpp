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

int n;
int a[N], b[N];

void check(int v){
	if(v == 1)
		return;
	for(int i = 1; i <= n; ++i)
		if(a[i]%v != 0 && b[i]%v != 0)
			return;
	
	printf("%d\n", v);
	exit(0);
}

void get(int x){
	for(int i = 2; i * i <= x; ++i){
		if(x%i == 0)
			check(i);
		while(x%i == 0)
			x /= i;
	}
	
	if(x > 1)
		check(x);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &a[i], &b[i]);
	
	get(a[1]), get(b[1]);
	puts("-1");
	return 0;
}