#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 2e5 + 10;
const int inf = 1e9;

vector < int > e[maxn];
int h[maxn];
bool use[maxn];
int tin[maxn];
int tout[maxn];
int tree0[maxn * 4];
int tree1[maxn * 4];
int upd0[maxn * 4];
int upd1[maxn * 4];
int a[maxn];
int t;

void dfs(int v, int hh){
	use[v] = 1;
	h[v] = hh;
	tin[v] = t++;
	for (int i = 0; i < (int)e[v].size(); i++)
		if (!use[e[v][i]])
			dfs(e[v][i], hh + 1);	
	tout[v] = t;
}

void push(int v, int ll, int rr, int * tree, int * upd){
	tree[v * 2 + 1] += upd[v] * ((ll + rr) / 2 - ll);
	tree[v * 2 + 2] += upd[v] * (rr - (ll + rr) / 2);
	upd[v * 2 + 1] += upd[v];
	upd[v * 2 + 2] += upd[v];
	upd[v] = 0;
}

int getSum(int v, int ll, int rr, int l, int r, int * tree, int * upd){
	if (ll >= r || l >= rr)
		return 0;
	if (l <= ll && rr <= r)
		return tree[v];
	push(v, ll, rr, tree, upd);
	return getSum(v * 2 + 1, ll, (ll + rr) / 2, l, r, tree, upd) +	
			getSum(v * 2 + 2, (ll + rr) / 2, rr, l, r, tree, upd);
	
}

void add(int v, int ll, int rr, int l, int r, int val, int * tree, int * upd){
	if (ll >= r || l >= rr)
		return;
	if (l <= ll && rr <= r){
		tree[v] += val * (rr - ll);
		upd[v] += val;
		return;
	}
	push(v, ll, rr, tree, upd);
	add(v * 2 + 1, ll, (ll + rr) / 2, l, r, val, tree, upd);
	add(v * 2 + 2, (ll + rr) / 2, rr, l, r, val, tree, upd);
	tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];	
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, type, v, u, val;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++){
		scanf("%d%d", &v, &u); v--; u--;
		e[v].pb(u);
		e[u].pb(v);		
	}
	dfs(0, 0);
	
	
	for (int i = 0; i < n; i++)
		h[i] = h[i] % 2;
// 	for (int i = 0; i < n; i++)
// 		cerr << tin[i] << " " << tout[i] << " " << h[i] <<  endl;

	
	for (int i = 0; i < n; i++)
		if (h[i] == 0)
			add(0, 0, n, tin[i], tin[i] + 1, a[i], tree0, upd0);
		else
			add(0, 0, n, tin[i], tin[i] + 1, a[i], tree1, upd1);
		 
	for (int i = 0; i < m; i++){
		scanf("%d", &type);
		if (type == 1){
			scanf("%d%d", &v, &val); v--;
			if (h[v] == 0){
				add(0, 0, n, tin[v], tout[v], val, tree0, upd0);
				add(0, 0, n, tin[v], tout[v], -val, tree1, upd1);			
			}
			else{
				add(0, 0, n, tin[v], tout[v], -val, tree0, upd0);
				add(0, 0, n, tin[v], tout[v], val, tree1, upd1);			
			}
		}
		else{	
			scanf("%d", &v); v--;
			if (h[v] == 0)
				printf("%d\n", getSum(0, 0, n, tin[v], tin[v] + 1, tree0, upd0));
			else
				printf("%d\n", getSum(0, 0, n, tin[v], tin[v] + 1, tree1, upd1));
		}
		
	}
	
	
	
	
    return 0;
}