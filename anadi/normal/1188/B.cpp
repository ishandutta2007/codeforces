#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, p, k;
map <int, int> M;

int kwa(int a){
	return (1LL * a * a) % p;
}

int main(){
	scanf("%d %d %d", &n, &p, &k);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		int t = (kwa(kwa(a)) - 1LL * k * a) % p;
		t = (t + p) % p;
		M[t]++;
	}
	
	long long ans = 0;
	for(auto v: M)
		ans += 1LL * v.nd * (v.nd - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}