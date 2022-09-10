#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;

int main(){
	int x;
	scanf("%d", &x);
	
	vector <int> ans(6, 0);
	for(int i = 0; i < 6; ++i)
		ans[i] = (x & (1 << i)) >> i;
	
	printf("%d\n", ans[5] * 32 + ans[0] * 16 + ans[2] * 8 + ans[3] * 4 + ans[1] * 2 + ans[4]);
	return 0;
}