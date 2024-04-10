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
 
int n, m, k, p[N], was[N], d[N];
vector< int > g[N], gr[N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[u].pb(v);
		gr[v].pb(u);
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
		scanf("%d", &p[i]);
	queue< int > q;
	q.push(p[k]);
	was[p[k]] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto to : g[v]){
			if(!was[to]){
				d[to] = d[v] + 1;
				was[to] = 1;
				q.push(to);
			}
		}	
	}
	int X = 0, Y = 0;
	for(int i = 1; i + 1 <= k; i++){
		bool x = 0, y = 0;
		for(auto to : gr[p[i]])
			if(d[to] == d[p[i]] - 1){
				if(to == p[i + 1])
					x = 1;
				else
					y = 1;
			}		
		if(!x)
			X++;
		if(y)
			Y++;
	}
	printf("%d %d", X, Y);
}