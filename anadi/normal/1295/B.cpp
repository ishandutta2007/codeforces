#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, x;
char in[N];
map <int, int> balances;

void solve(){
	scanf("%d %d", &n, &x);
	scanf("%s", in + 1);
	balances.clear();
	
	int curBalance = 0;
	for(int i = 1; i <= n; ++i){
		balances[curBalance]++;
		if(in[i] == '0')
			curBalance++;
		else
			curBalance--;
	}
	
	if(curBalance == 0){
		if(balances[x] != 0)
			puts("-1");
		else
			puts("0");
		return;
	}
	
	LL ans = 0;
	for(auto v: balances){
		int aim = x - v.st;
		if(abs(aim) % abs(curBalance) != 0)
			continue;
		
		if(aim / curBalance < 0)
			continue;
		ans += v.nd;
	}
	
	printf("%lld\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}