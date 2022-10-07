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

const int maxn = 1e6 + 2;
const int inf = 1e9;


vector < int > e[maxn];
int st[maxn];
int c[maxn];
bool b[maxn];
int p[maxn];
int where[maxn];
vector < pair < int, int > > edge;
vector < vector < int > > ans;

int getId(int v){
	if (p[v] == v) return v;
	return p[v] = getId(p[v]);	
}

void merge(int v, int u){
	v = getId(v);
	u = getId(u);
	p[v] = u;	
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, v, u, cnt;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &v, &u); v--; u--;
		e[v].pb(u);
		e[u].pb(v);
		st[v]++;
		st[u]++;		
	}
	v = 0; 
	for (int i = 0; i < n; i++)
		if (st[i] < st[v])
			v = i;
	
	memset(c, -1, sizeof(c));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < (int)e[v].size(); i++)
		b[e[v][i]] = 1;
	
	for (int i = 0; i < n; i++)
		if (!b[i])
			c[i] = 0;
	
	cnt = n - e[v].size();
	
	
	for (int i = 0; i < n; i++)
		if (c[i] == -1){
			if ((int)e[i].size() < cnt){
				cnt++;
				c[i] = 0;				
			}
			else{
				memset(b, 0, sizeof(b));
				for (int j = 0; j < (int)e[i].size(); j++)
					b[e[i][j]] = 1;
				for (int j = 0; j < n; j++)
					if (!b[j])
						edge.pb(mp(i, j));
			}
		}
	for (int i = 0; i < n; i++)
		p[i] = (c[i] == -1)? i: v;
	for (int i = 0; i < (int)edge.size(); i++){
		v = edge[i].fr;
		u = edge[i].sc;
		if (getId(v) != getId(u)){
			merge(v, u);
		}
	}	
	for (int i = 0; i < n; i++)
		getId(i);
	memset(where, -1, sizeof(where));
	vector < int > empty;
// 	for (int i = 0; i < n; i++)
// 		epr("%d ", p[i]);
// 	epr("\n");
	for (int i = 0; i < n; i++){
		if (where[p[i]] == -1){
			where[p[i]] = ans.size();
			ans.pb(empty);
		}
		ans[where[p[i]]].pb(i);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++){
		printf("%d ", (int)ans[i].size());
		for (int j = 0; j < (int)ans[i].size(); j++)
			printf("%d ", ans[i][j] + 1);
		printf("\n");
	}

    return 0;
}