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

int n;
vector <int> who[N];

LL ans;
int price[N], need[N];
priority_queue <int> Q;

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		who[i].clear();
	while(!Q.empty())	Q.pop();

	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &need[i], &price[i]);
		who[need[i]].push_back(price[i]);
	}
	
	ans = 0;
	for(int i = n; i >= 1; --i){
		for(auto v: who[i])
			Q.push(-v);
		
		while((int)Q.size() > n - i){
			ans -= Q.top();
			Q.pop();
		}
	}
	
	printf("%lld\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}