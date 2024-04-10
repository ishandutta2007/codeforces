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
int p[N];
LL out[N];
LL t, in[N];

int main(){
	scanf("%d %lld", &n, &t);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &in[i]);
		out[i] = in[i] + t;
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i]);
		if(i > p[i] || p[i - 1] > p[i]){
			puts("No");
			return 0;
		}
		
		if(p[i - 1] >= i)
			out[i - 1] = in[i] + t;
	}

	for(int i = 1; i <= n; ++i)
		out[i] = max(out[i], out[i - 1] + 1);
	
	for(int i = 1; i <= n; ++i){
		if(p[i] < n && in[p[i] + 1] + t <= out[p[i]]){
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	for(int i = 1; i <= n; ++i)
		printf("%lld ", out[i]);
	return 0;
}