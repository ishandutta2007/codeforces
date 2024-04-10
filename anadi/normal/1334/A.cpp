#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;

void solve(){
	bool ok = true;
	int lp = 0, lc = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int p, c;
		scanf("%d %d", &p, &c);
		
		if(c - lc > p - lp)
			ok = false;
		
		if(c < lc || p < lp)
			ok = false;
		lp = p, lc = c;
	}
	
	puts(ok ? "YES" : "NO");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}