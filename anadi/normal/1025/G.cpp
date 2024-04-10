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
int in[N];
int cnt[N];

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a)%MX;
		
		b >>= 1;
		a = (1LL * a * a)%MX;
	}
	
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		if(in[i] > 0)
			cnt[in[i]]++;
	}
	
	int sum = 0;
	for(int i = 1; i <= n; ++i)
		if(in[i] == -1)
			sum = (sum + fast(2, cnt[i]) - 1)%MX;
	
	sum = MX - sum;
	sum = (sum + fast(2, n - 1) - 1)%MX;
	printf("%d\n", sum);
	return 0;
}