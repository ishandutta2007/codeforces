#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

LL n, k, m;
LL czas[N];

int solve(LL leftTime, int el){
	int res = 0;
	for(int i = 1; i <= k; ++i){
		if(czas[i] * el <= leftTime){
			res += el;
			continue;
		}
		
		LL cur = czas[i] - czas[i - 1];
		res += (leftTime - czas[i - 1] * el) / cur;
		break;
	}
	
	return res;
}

int main(){
	scanf("%lld %lld %lld", &n, &k, &m);
	for(int i = 1; i <= k; ++i)
		scanf("%lld", &czas[i]);
	sort(czas + 1, czas + k + 1);
	
	for(int i = 2; i <= k; ++i)
		czas[i] += czas[i - 1];
	
	LL res = 0;
	for(int i = 0; i <= n; ++i)
		if(1LL * i * czas[k] <= m)
			res = max(res, solve(m - 1LL * i * czas[k], n - i) + i * (k + 1));
	printf("%lld\n", res);
	return 0;
}