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

int n;
int in[N];

long long s = 0;
vector <long long> primes;

LL check(LL val){
	LL pref = 0, ans = 0;
	for(int i = 1; i < n; ++i){
		pref += in[i];
		pref %= val;
		ans += min(pref, val - pref);
	}
	
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		s += in[i];
	}
	
	if(s == 1){
		puts("-1");
		exit(0);
	}
	
	LL ans = INF;
	for(int i = 2; 1LL * i * i <= s; ++i){
		if(s % i == 0)
			primes.push_back(i);

		while(s % i == 0)
			s /= i;
	}
	
	if(s > 1)
		primes.push_back(s);

	for(auto v: primes)
		ans = min(ans, check(v));
	printf("%lld\n", ans);
	return 0;
}