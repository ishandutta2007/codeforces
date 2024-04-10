#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 2e5 + 7;

int n;
char s[N];
int ans[N];
bool vis[N];

int sum, cyc;
void dfs(int u){
	if(vis[u])
		return;

	vis[u] = true;
	sum += s[u] - '0';

	dfs((u + cyc)%n);
}

bool good(){
	for(int i = 0; i < n; ++i)
		vis[i] = false;
	
	for(int i = 0; i < n; ++i){
		if(vis[i])	continue;
		sum = 0; dfs(i);
		if(sum & 1)	return false;
	}
	
	return true;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		if(n%i == 0){
			cyc = i;
			ans[i] = good();
			res += ans[i];
		}
		else
			res += ans[__gcd(i, n)];
	printf("%d\n", res);
	return 0;
}