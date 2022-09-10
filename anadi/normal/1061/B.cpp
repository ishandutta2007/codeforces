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

int n, m;
int val[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	sort(val + 1, val + n + 1);
	
	LL res = 0LL; 
	int last = m + 1;
	
	for(int i = n; i >= 1; --i){
		int Need = max(min(val[i], last - 1) - val[i - 1], 1);
		last = min(last - 1, min(val[i], val[i - 1] + 1));
		res += val[i] - Need;
	}
	
	printf("%lld\n", res);
	return 0;
}