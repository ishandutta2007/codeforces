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
char in[N];
int ans[N];

void getMax(){
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		ans[i] = 0;

	for(int i = 1; i < n; ++i)
		if(in[i] == '<')
			ans[i] = ++cnt;
	
	for(int i = n; i >= 1; --i)
		if(ans[i] == 0)
			ans[i] = ++cnt;

	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
}

void getMin(){
	int cnt = 0;
	for(int i = n; i >= 1; --i){
		int it = i - 1;
		while(it > 0 && in[it] == '<')
			--it;
		
		for(int j = it + 1; j <= i; ++j)
			ans[j] = ++cnt;
		i = it + 1;
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
}

void solve(){
	scanf("%d", &n);
	scanf("%s", in + 1);

	getMin();
	getMax();
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}