#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, m;
int u[500500];
int v[500500];
int w[500500];
int p[500500];
vector<int> qu[500500];
vector<int> G[500500];
int it[500500];
int st[500500];
int ok[500500];
int cmp(int i, int j){
	return w[i] < w[j];
}
int gggg;
int wwww[500500];
int pp[500500];
int uuu[500500];
int get(int v){
	if(pp[v] == v) return v;
	return pp[v] = get(pp[v]);
}
vector<int> D[500500];
int good;
void dfs(int v, int p){
	wwww[v] = gggg;
	uuu[v] = 1;
	for(int i = 0; i <D[v].size(); i++){
		int to = D[v][i];
		if(to == p)continue;
		if(wwww[to] != gggg) {
			dfs(to, v);
		}
		else if(uuu[to] == 1){
			good = 0;
		}
	}
	uuu[v] = 2;
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		pp[i] = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		p[i] = i;
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int k;
		scanf("%d", &k);
		for(int j = 0, t; j < k; j++){
			scanf("%d", &t);
			--t;
			G[i].pb(t);
		}
	}
	for(int i = 0 ; i<q; i++){
		sort(all(G[i]), cmp);
		ok[i] = 1;
		for(int j = 0; j < G[i].size(); j++){
			if(j == 0 || w[G[i][j]] != w[G[i][j-1]]){
				qu[w[G[i][j]]].pb(i);
			}
		}
	}
	sort(p, p + m, cmp);
	for(int i = 0; i < m; ){
		int j = i;
		while(i < m && w[p[j]] == w[p[i]]) i++;
		int y = w[p[j]];
		for(int k = 0; k < qu[y].size(); k++){
			int ind = qu[y][k];
			st[ind] = it[ind];
			while(it[ind] < G[ind].size() && w[G[ind][it[ind]]] == y) it[ind]++;
			gggg++;
			int cnt = 0;
			set<int> VV;
			map<pii, int> HH;
			for(int T = st[ind]; T < it[ind]; T++){
				int U = get(u[G[ind][T]]);
				int V = get(v[G[ind][T]]);
				if(U==V) ok[ind] = 0;
				if(HH[mp(U, V)]) ok[ind] = 0;
				HH[mp(U, V)] = 1;
				HH[mp(V, U)] = 1;
				D[U].pb(V);
				D[V].pb(U);
				VV.insert(V);
				VV.insert(U);
			}
			forit(it, VV){
				int hh = *it;
				good = 1;
				if(wwww[hh] != gggg){
					dfs(hh, -1);
					ok[ind] = (ok[ind] & good);
				}
			}
			for(int T = st[ind]; T < it[ind]; T++){
				int U = get(u[G[ind][T]]);
				int V = get(v[G[ind][T]]);
				D[U].clear();
				D[V].clear();
			}
			
		}
		while(j < i){
			int U = get(u[p[j]]);
			int V = get(v[p[j]]);
			if(U!=V){
				pp[U] = V;
			}
			j++;
		}
	}
	for(int i = 0; i < q; i++){
		if(ok[i]) printf("YES\n");
		else printf("NO\n");
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}