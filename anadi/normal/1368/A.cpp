#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

void solve(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int ans = 0;
	while(a <= c && b <= c){
		if(a < b)
			a += b;
		else
			b += a;
		++ans;
	}
	
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}