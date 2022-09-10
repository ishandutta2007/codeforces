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
LL ans[N];
LL poss[N];

int nr(int a){
	return a > n ? a - n : a;
}

LL get(LL a, LL b, LL c){
	return (a + c - 1) / c * c + b;
}

void solve(int t){
	t += n;
	ans[nr(t)] = poss[nr(t)];
	for(int i = 1; i < n; ++i){
		--t;
		ans[nr(t)] = get(poss[nr(t)], in[t], ans[nr(t + 1)]);
		assert(ans[nr(t)] >= poss[nr(t)]);
	}
	
	puts("YES"); ans[n + 1] = ans[1];
	for(int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	exit(0);
}

int main(){
	scanf("%d", &n); 
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		in[i + n] = in[i];
	}

	poss[1] = max(in[1], in[n] + 1);
	for(int i = 2; i <= n; ++i)
		poss[i] = max(in[i], in[i - 1] + 1);
	
	bool ok = true;
	for(int i = 1; i <= n; ++i)
		ok &= in[i] == 0;
	
	if(ok){
		puts("YES");
		for(int i = 1; i <= n; ++i)
			printf("1 ");
		exit(0);
	}

	for(int i = 1; i <= n; ++i)
		if(poss[nr(i + 1)] > poss[i] && poss[i] == in[i])
			solve(i);
	puts("NO");
	return 0;
}