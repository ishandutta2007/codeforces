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

int n;
int ans[N];

int main(){
	scanf("%d", &n); int t = 0;
	for(int i = 0; i < n + n; i += 2){
		ans[i / 2 + 1] = (i ^ t) + 1;
		t ^= 1;
		ans[n + i / 2 + 1] = (i ^ t) + 1;
	}
	
	if(n % 2 == 0){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	for(int i = 1; i <= n + n; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}