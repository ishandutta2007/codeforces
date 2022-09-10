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

int n, k;
int fi[N];

int main(){
	scanf("%d %d", &n, &k);
	if(k == 1){
		puts("3");
		return 0;
	}
	
	for(int i = 1; i < N; ++i)
		fi[i] = i;
	
	for(int i = 2; i < N; ++i){
		if(fi[i] != i)	continue;
		for(int j = i; j < N; j += i){
			fi[j] /= i;
			fi[j] *= i - 1;
		}
	}
	
	long long ans = 2;
	sort(fi + 3, fi + n + 1);
	for(int i = 1; i <= k; ++i)
		ans += fi[i + 2];
	
	printf("%lld\n", ans);
	return 0;
}