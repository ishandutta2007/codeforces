#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

void solve(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(a <= b){
		printf("%d\n", b);
		return;
	}
	
	a -= b;
	if(c <= d){
		puts("-1");
		return;
	}
	
	LL diff = c - d;
	LL turns = (a + diff - 1) / diff;
	printf("%lld\n", b + turns * c);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}