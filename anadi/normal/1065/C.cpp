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
int h[N];
int mx = 0, mn = N;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);

		h[a]++;
		mn = min(mn, a);
		mx = max(mx, a);
	}
	
	int res = 0; int s = 0;
	for(int i = mx; i > mn; --i){
		s += h[i];
		h[i - 1] += h[i];

		if(s > k){
			s = h[i];
			++res;
		}
	}
	
	if(s)
		++res;
	
	printf("%d\n", res);
	return 0;
}