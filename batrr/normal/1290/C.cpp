#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< int > g[N];
int pr[N], pc[N], sz[N][2];
int n, k, cur;
char s[N];

void pp(int v){
	if(pr[v] == v)
		return;
	pp(pr[v]);
	pc[v] ^= pc[pr[v]];
	pr[v] = pr[pr[v]];
}
void f(int v, int l){
	if(v == k)
		cur += l * sz[v][0];
	else
		cur += l * min(sz[v][0], sz[v][1]);
} 
void add(int v, int u, int c){
	pp(v);
	c ^= pc[v];
	pp(u);
	c ^= pc[u];
	
	v = pr[v];
	u = pr[u];

	if(v == u)
		return;
	if(v < u)
		swap(v, u);

	f(v, -1);
	f(u, -1);

	pr[u] = v;
	pc[u] = c;	
	                     
	sz[v][0] += sz[u][c];
	sz[v][1] += sz[u][c ^ 1];

	f(v, 1);
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(int i = 0; i < k; i++){
		int c;
		scanf("%d", &c);
		while(c--){
			int d;
			scanf("%d", &d);
			g[d - 1].pb(i);
		}
	}

	for(int i = 0; i <= k; i++)
		pr[i] = i, pc[i] = 0, sz[i][0] = 1, sz[i][1] = 0;
	cur = 1;	
	for(int i = 0; i < n; i++){
		if(g[i].size() == 1){
			int v = g[i][0];
			if(s[i] == '0')
            	add(v, k, 0);
			else
				add(v, k, 1);
		}
		if(g[i].size() == 2){
			int v = g[i][0];
			int u = g[i][1];
        	if(s[i] == '0')
            	add(v, u, 1);
			else
				add(v, u, 0);
		}
		printf("%d\n", cur - 1);
	}
}