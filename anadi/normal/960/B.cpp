#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, a, b;
int tab[N];
priority_queue <int> Q;

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	for(int i = 1; i <= n; ++i){
		int a; scanf("%d", &a);
		tab[i] -= a; tab[i] = abs(tab[i]);
		Q.push(tab[i]);
	}
	
	a += b;
	while(a--){
		int x = Q.top();
		Q.pop();
		if(x > 0)
			Q.push(x - 1);
		else
			Q.push(x + 1);
	}
	
	LL res = 0LL;
	while(!Q.empty()){
		int x = Q.top();
		Q.pop();		
		res += 1LL * x * x;
	}
	
	printf("%lld\n", res);
	return 0;
}