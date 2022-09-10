#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;

int main(){
	int x;
	scanf("%d", &x);
	
	vector <int> primes;
	for(int i = 2; i <= x; ++i){
		while(x % i == 0){
			x /= i;
			primes.push_back(i);
		}
	}
	
	assert(x == 1);
	for(auto v: primes)
		printf("%d", v);
	puts("");
	return 0;
}