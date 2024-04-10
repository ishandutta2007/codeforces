#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, q;
int rep[N];

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	rep[Find(a)] = Find(b);
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n + m; ++i)
		rep[i] = i;
	
	if(n == 1 || m == 1){
		printf("%d\n", n * m - q);
		return 0;
	}
	
	while(q--){
		int u, v;
		scanf("%d %d", &u, &v);
		Union(u, n + v);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n + m; ++i)
		if(Find(i) == i)
			++cnt;
	
	printf("%d\n", cnt - 1);
	return 0;
}