#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 107;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
PII dp[N];
pair <int, PII> in[N];

bool ok(){
	dp[0] = {m, m};
	for(int i = 1; i <= n; ++i){
		PII prv = dp[i - 1];
		prv.st -= in[i].st - in[i - 1].st;
		prv.nd += in[i].st - in[i - 1].st;
		
		prv.st = max(prv.st, in[i].nd.st);
		prv.nd = min(prv.nd, in[i].nd.nd);
		
		if(prv.nd < in[i].nd.st)
			return false;
		if(in[i].nd.nd < prv.st)
			return false;
		if(prv.nd < prv.st)
			return false;
		dp[i] = prv;
	}
	
	return true;
}

void solve(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d %d", &in[i].st, &in[i].nd.st, &in[i].nd.nd);
	sort(in + 1, in + n + 1);
	
	if(ok())
		puts("YES");
	else
		puts("NO");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}