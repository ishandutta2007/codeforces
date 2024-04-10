#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;
const LL bigInf = 1e18 + 9LL;

int n, k;
int ans[N];
set <int> S;
priority_queue <PII> Q;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		S.insert(k + i);
		int x;
		scanf("%d", &x);
		Q.push({x, i});
	}
	
	LL res = 0LL;
	while(!Q.empty()){
		int cost = Q.top().st, czas = Q.top().nd;
		Q.pop();
		
		auto it = S.lower_bound(czas);
		res += 1LL * ((*it) - czas) * cost;
		ans[czas] = *it;
		S.erase(*it);
	}
	
	printf("%lld\n", res);
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}