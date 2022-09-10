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

int n, k;
map <int, int> M;

LL licz(int a){
	return 1LL * a * (a - 1) / 2;
}

int main(){
	scanf("%d %d", &n, &k);
	k = 1 << k;
	
	int cur = 0; M[0]++;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		cur ^= a;
		M[cur]++;
	}
	
	LL res = 1LL * n * (n + 1) / 2LL;
	int half = k / 2;
	for(auto v: M){
		if(v.st >= half && M.count(v.st ^ (k - 1)))
			continue;
		
		int rv = v.nd + (M.count(v.st ^ (k - 1)) ? M[v.st ^ (k - 1)] : 0);
		res -= licz(rv / 2) + licz((rv + 1) / 2);
	}
	
	printf("%lld\n", res);
	return 0;
}