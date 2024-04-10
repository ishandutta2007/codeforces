#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

int n,k;
ll d[N][7];
vi g[N];

ll ans;

ll cnt[N], c[N];

void dfs(int v,int p = -1){
	d[v][0] = 1;
	c[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to,v);
		for(int j = 0; j < k; j++){
			for(int s = 0; s < k; s++){
				if(j + s + 1 >= k){
					ans += 1ll * d[v][s] * d[to][j];
				}
				if((j + s + 1) % k != 0){
					ans += 1ll * d[v][s] * d[to][j];
				}
			}
		}
		ans += cnt[v] * c[to];
		ans += cnt[to] * c[v];
		c[v] += c[to];
		for(int j = 0; j < k; j++){
			d[v][(j + 1) % k] += d[to][j];
		}
		cnt[v] += d[to][k - 1];
		cnt[v] += cnt[to];
	}
}

int main () {
	scanf("%d%d",&n,&k);
	for(int i = 1,u,v; i < n; i++){
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	//dfs1(1);
	dfs(1);
	printf("%lld", ans);

return 0;
}