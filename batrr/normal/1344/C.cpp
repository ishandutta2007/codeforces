#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 

vector< int > g[N], gr[N];
int n, m, col[N], ans;
bool wt[N], wb[N], was[N];
void f(int v){
	if(col[v] == 2)
		return;
	if(col[v] == 1){
		printf("-1");
		exit(0);
	}
	col[v] = 1;
	for(auto to : g[v])
		f(to);
	col[v] = 2;
}
void ft(int v){
	if(wt[v])
		return;
	wt[v] = 1;
	for(auto to : g[v])
		ft(to);
}
void fb(int v){
	if(wb[v])
		return;
	wb[v] = 1;
	for(auto to : gr[v])
		fb(to);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		v--, u--;
		g[v].pb(u);
		gr[u].pb(v);
	}
	for(int i = 0; i < n; i++)
		if(col[i] == 0)
			f(i);
	for(int i = 0; i < n; i++){
		if(!wt[i] && !wb[i]){
			ans++;
			was[i] = 1;
		}
		ft(i);
		fb(i);	
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i++)
		printf("%c", (was[i] ? 'A' : 'E'));
}