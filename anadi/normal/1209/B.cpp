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

int n;
int cnt[N];
char on[N];

int main(){
	scanf("%d", &n);
	scanf("%s", on + 1);
	
	for(int i = 1; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		
		for(int j = 0; j < b; ++j)
			cnt[j] += on[i] == '1';
		
		bool ok = on[i] == '1';
		for(int j = 0; j <= 10000; ++j){
			if(j % a == 0)
				ok ^= 1;			
			cnt[j + b] += ok;
		}
	}
	
	int ans = 0;
	for(int i = 0; i <= 10000; ++i)
		ans = max(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}