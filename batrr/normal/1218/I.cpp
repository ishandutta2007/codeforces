#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 4100, M = 2100;

int n, m, a[M][M], b[M], c[N];      
char s[M][M], t[M][M], p[M];
vector< pii > g[N];
bool used[N];
void no(){
	printf("-1");
	exit(0);
}
void dfs(int v){
	if(used[v])
		return;
	used[v] = 1;
	for(auto to : g[v]){
		if(!used[to.f]){
			if(c[to.f] == -1)
            	c[to.f] = c[v] ^ to.s;
			if(c[to.f] != c[v] ^ to.s)
				no();
			dfs(to.f);
		}else if(c[to.f] != c[v] ^ to.s){
			no();		
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", &s[i]);
	for(int i = 0; i < n; i++)
		scanf("%s", &t[i]);
	scanf("%s", &p);
	for(int i = 0; i < n; i++)	
		for(int j = 0; j < n; j++)
			a[i][j] = (s[i][j] != t[i][j]);
    for(int i = 0; i < n; i++)
    	b[i] = (p[i] == '1');
	
	for(int i = 0; i < n + n; i++)
		c[i] = -1;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if(a[i][j]){
				if(b[i] == 0 && b[j] == 0){
					no();
				}
				if(b[i] == 1 && b[j] == 0){
					if(c[j + n] == 0)
						no();
					c[j + n] = 1;
				}
				if(b[i] == 0 && b[j] == 1){
					if(c[i] == 0)
						no();
					c[i] = 1;				
				}
				if(b[i] == 1 && b[j] == 1){
					g[i].pb({j + n, 1});
					g[j + n].pb({i, 1});				
				}
			}else{
				if(b[i] == 0 && b[j] == 0){
				}
				if(b[i] == 1 && b[j] == 0){
					if(c[j + n] == 1)
						no();
					c[j + n] = 0;
				}
				if(b[i] == 0 && b[j] == 1){
					if(c[i] == 1)
						no();
					c[i] = 0;				
				}
				if(b[i] == 1 && b[j] == 1){
					g[i].pb({j + n, 0});
					g[j + n].pb({i, 0});
				}
			}
		}
	for(int i = 0; i < n + n; i++)
		if(c[i] != -1)
			dfs(i);
	for(int i = 0; i < n + n; i++){
		if(c[i] == -1){
			c[i] = 0;
			dfs(i);
		}
	}
	int cnt = 0;
	for(int i = 0; i < n + n; i++)
		cnt += c[i];
	printf("%d\n", cnt);
	for(int i = 0; i < n + n; i++){
		if(c[i] == 0)
			continue;
		if(i < n)
			printf("row %d\n", i);
		else
			printf("col %d\n", i - n);
	}
	return 0;

}