#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	cin >> n;
	LL d = 2;
	while(d * d <= n){
		if(n%d == 0)
			break;
		++d;
	}
	
	if(n%d != 0)
		puts("1");
	else
		printf("%lld\n", 1 + (n - d) / 2LL);
	return 0;
}