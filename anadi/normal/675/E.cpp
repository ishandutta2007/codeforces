#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const LL INF = 1e9 + 7;
const int mxn = 1e6 + 7;

#define PII pair <int, int>
#define mp make_pair
#define st first
#define nd second
#define PLL pair <LL, LL>

int n;
int T[mxn];
LL dp[mxn];
PLL tree[mxn];
int K = 1;

void add(int x, LL val){
	x += K;
	tree[x] = mp(val, x - K);
	while(x > 1){
		x /= 2;
		tree[x] = min(tree[2 * x], tree[2 * x + 1]);
	}
}

PLL mn(int from, int to){
	from += K;
	to += K;
	
	PLL res = mp(INF * INF, INF);
	while(from < to){
		if(from%2 == 1){
			res = min(res, tree[from]);
			++from;
		}
		if(to%2 == 0){
			res = min(res, tree[to]);
			--to;
		}
		
		from /= 2;
		to /= 2;
	}
	
	if(from == to)
		res = min(res, tree[to]);
	return res;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
		scanf("%d", &T[i]);
	
	while(K < n)
		K *= 2;
	--K;
	
	dp[n] = 0LL;
	add(n, n);
	for(int i = n - 1; i >= 1; --i){
		PLL x = mn(i + 1, T[i]);
		x.st -= x.nd;
		x.st += n - T[i];
		x.st += x.nd - i;
		dp[i] = x.st;
		add(i, dp[i] + i);
	}
	
	LL res = 0LL;
	for(int i = 1; i <= n; ++i)
		res += dp[i];
	printf("%I64d\n", res);
	return 0;
}