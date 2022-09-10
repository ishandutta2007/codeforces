#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, k, ans;
priority_queue <int> Q;

int main(){
	scanf("%d %d %d", &n, &m, &k);
	k = n - k;
	
	int last;
	scanf("%d", &last);

	ans = n;
	for(int i = 1; i < n; ++i){
		int a;
		scanf("%d", &a);
		Q.push(-(a - last - 1));
		last = a;
	}
	
	while(!Q.empty() && k--){
		ans -= Q.top();
		Q.pop();
	}
	
	printf("%d\n", ans);
	return 0;
}