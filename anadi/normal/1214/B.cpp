#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int main(){
	int b, g, n;
	cin >> b >> g >> n;
	
	int ans = 0;
	for(int i = 0; i <= n; ++i)
		if(b >= i && g >= n - i)
			++ans;
	printf("%d\n", ans);
	return 0;
}