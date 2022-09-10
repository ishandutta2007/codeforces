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

int n, I;
int cnt[N];
map <int, int> M;

int main(){
	scanf("%d %d", &n, &I);
	I = 8 * I / n;
	I = 1 << min(I, 20);
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		M[a]++;
	}
	
	int it = 0;
	for(auto v: M)
		cnt[++it] = v.nd;
	
	n = it;
	for(int i = 1; i <= n; ++i)
		cnt[i] += cnt[i - 1];
		
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, cnt[min(n, i + I - 1)] - cnt[i - 1]);
	
	printf("%d\n", cnt[n] - ans);
	return 0;
}