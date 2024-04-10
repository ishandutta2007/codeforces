#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, x;

void solve(){
	scanf("%d %d", &n, &x); 
	int mx = 0; bool ok = false;
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		
		if(a == x)
			ok = true;
		mx = max(mx, a);
	}
	
	if(ok)
		puts("1");
	else{
		int ans = (x + mx - 1) / mx;
		printf("%d\n", max(2, ans));
	}
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}