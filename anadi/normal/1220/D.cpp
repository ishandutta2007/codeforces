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
vector <LL> ans[100];

int getPt(LL a){
	int ans = 0;
	while(a % 2 == 0)
		++ans, a /= 2LL;
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		LL a;
		scanf("%lld", &a);
		ans[getPt(a)].push_back(a);
	}
	
	int best = 0;
	for(int i = 1; i < 70; ++i)
		if(ans[i].size() > ans[best].size())
			best = i;
	
	printf("%d\n", n - (int)ans[best].size());
	for(int i = 0; i < 70; ++i)
		if(i != best)
			for(auto v: ans[i])
				printf("%lld ", v);
	puts("");
	return 0;
}