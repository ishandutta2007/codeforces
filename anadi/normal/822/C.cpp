#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 200 * 1000 + 9;
const int inf = 1000 * 1000 * 1000 + 9;

int n, x;
int l[N];
priority_queue <pair <int, PII> > Q;

int main(){
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Q.push({-a, {c, b - a + 1}});
		Q.push({-b, {-c, b - a + 1}});
	}
	
	for(int i = 0; i <= x; ++i)
		l[i] = inf;
	
	int bestRes = 2 * inf;
	while(!Q.empty()){
		PII k = Q.top().nd;
		Q.pop();
		
		if(k.st < 0)
			l[k.nd] = min(l[k.nd], -k.st);
		else
			if(k.nd <= x && l[x - k.nd] < inf)
				bestRes = min(bestRes, k.st + l[x - k.nd]);
	}
	
	if(bestRes == 2 * inf)
		bestRes = -1;
	printf("%d\n", bestRes);
	return 0;
}