#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

bool prime(LL a){
	for(LL i = 2; i * i <= a; ++i)
		if(a%i == 0)
			return false;
	return true;
}

void solve(){
	LL a, b;
	scanf("%lld %lld", &a, &b);
	
	if(b + 1 < a){
		puts("NO");
		return;
	}
	
	LL x = a + b;
	if(prime(x))
		puts("YES");
	else
		puts("NO");
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}