#include <bits/stdc++.h>

using namespace std;

typedef double LD;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define pb push_back
#define PLL pair <LL, LL>
#define pb push_back

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7LL;
const int mxn = 29;
const int MaxMask = (1 << 20) + 9;

double dp[MaxMask];
double ans[mxn];
double p[mxn];
int n, k;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lf", &p[i]);
	
	int nzero = 0;
	for(int i = 1; i <= n; ++i)
		if(p[i] != 0.0)
			nzero++;

	if(nzero <= k){
		for(int i = 1; i <= n; ++i)
			p[i] == 0 ? printf("0.0 ") : printf("1.0 ");
		return 0;
	}
	
	dp[0] = 1.0;
	for(int i = 0; i < (1 << n); ++i){

		int ile = 0;
		double sum = 0.0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j)){
				++ile;
				sum += p[j + 1];
			}
		
		if(ile == k)
			for(int j = 0; j < n; ++j)
				if(i & (1 << j))
					ans[j + 1] += dp[i];

		if(ile >= k)
			continue;

		sum = 1.0 - sum;
		for(int j = 0; j < n; ++j)
			if(!(i & (1 << j)))
				dp[i + (1 << j)] += dp[i] * p[j + 1] / sum;
	}

	for(int i = 1; i <= n; ++i)
		p[i] == 0.0 ? printf("0.0 ") : printf("%.7lf ", ans[i]);
	
	return 0;
}