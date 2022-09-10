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
const int T = 1 << 20;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
LL in[N][2];
LL sum[N][2];

int main(){
	scanf("%d", &n);
	for(int t = 0; t < 2; ++t)
		for(int i = 1; i <= n; ++i)
			scanf("%I64d", &sum[i][t]),
			sum[i][t] += sum[i - 1][t];
	
	for(int i = n; i >= 1; --i){
		in[i][0] = in[i + 1][0] + sum[n][0] - sum[i][0] + sum[n][1] - sum[i][1] + (2 * (n - i) + 1) * (sum[i][1] - sum[i - 1][1]);
		in[i][1] = in[i + 1][1] + sum[n][0] - sum[i][0] + sum[n][1] - sum[i][1] + (2 * (n - i) + 1) * (sum[i][0] - sum[i - 1][0]);
	}
	
	LL res = 0;
	LL cur = 0LL;
	
	for(int i = 1; i <= n; ++i){
		if(i & 1){
			res = max(res, in[i][0] + 2 * (i - 1) * (sum[n][0] - sum[i - 1][0] + sum[n][1] - sum[i - 1][1]) + cur);
			cur += 2 * (i - 1) * (sum[i][0] - sum[i - 1][0]) + (2 * (i - 1) + 1) * (sum[i][1] - sum[i - 1][1]);
			res = max(res, in[i + 1][1] + 2 * i * (sum[n][0] - sum[i][0] + sum[n][1] - sum[i][1]) + cur);
		}
		else{
			res = max(res, in[i][1] + 2 * (i - 1) * (sum[n][0] - sum[i - 1][0] + sum[n][1] - sum[i - 1][1]) + cur);
			cur += 2 * (i - 1) * (sum[i][1] - sum[i - 1][1]) + (2 * (i - 1) + 1) * (sum[i][0] - sum[i - 1][0]);
			res = max(res, in[i + 1][0] + 2 * i * (sum[n][0] - sum[i][0] + sum[n][1] - sum[i][1]) + cur);
		}
	}
	
	printf("%I64d\n", res);
	return 0;
}