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
const int mod = (int) 1e9 + 7;
using namespace std;
vector<int> G[100100];
vector<int> GR[100100];
bool was[100100][51];
int n, m, d;
char h[100100][51];
vector<pii> ord;

int C[100100][51];
vector<int> id;
int COST[100100*50];
vector<int> g[100100*50];
vector<int> gr[100100*50];
vector<int> ORD;
int DP[100100*50];
bool U[100100*50];
int IND[100100][50];

void dfs(int V, int K){
	vector<pii> cur;
	cur.pb(mp(V, K));
	
	IND[V][K] = 0;
	was[V][K] = 1;
	while(cur.size() > 0){
		int v = cur.back().f;
		int k = cur.back().s;
		if(IND[v][k] == G[v].size()){
			ord.pb(mp(v, k));
			cur.pop_back();
		}
		else {
			int to = G[v][IND[v][k]];
			int j = (k + 1) % d;
			
			if(was[to][j] == 0){	
				cur.pb(mp(to, j));
				was[to][j] = 1;
				IND[to][j] = 0;
			}

			IND[v][k]++;
		}
	}
}

int CC[100100];
int TT;
void dfs2(int V, int K, int col){
	vector<pii> cur;
	cur.pb(mp(V, K));
	IND[V][K] = 0;
	was[V][K] = 1;
	TT++;
	while(cur.size() > 0){
		int v = cur.back().f;
		int k = cur.back().s;
		
		if(IND[v][k] >= GR[v].size()){	
			cur.pop_back();
			
			if(h[v][k] == '1' && CC[v] != TT) {
			    id.pb(v);
			    CC[v] = TT;
			}
				C[v][k] = col;
		}
		else {
			int to = GR[v][IND[v][k]];
			int j = (k + d- 1) % d;
			if(was[to][j] == 0){	
				cur.pb(mp(to, j));
				was[to][j] = 1;
				IND[to][j] = 0;
			}
			IND[v][k]++;
		}
	}
}
int II[100100*51];
void DFS(int v){
    TT++;
	vector<int> cur;
	cur.pb(v);
	U[v] = 1;
	while(cur.size() > 0){
		int v = cur.back();
		
		if(II[v] == g[v].size()){
			ORD.pb(v);
			cur.pop_back();
		}
		else {
			int to = g[v][II[v]];
			
			if(U[to] == 0) {
				U[to] = 1;
				cur.pb(to);
			}
			II[v]++;
		}
	}
}
void solve(){
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		G[x].pb(y);
		GR[y].pb(x);
	}
	for(int i = 0; i < n; i++) {
		scanf("%s", h[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < d; j++){
			if(was[i][j]) continue;
			dfs(i, j);
		}
	}
	memset(was, 0, sizeof was);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < d; j++) was[i][j] = 0;
	reverse(all(ord));
	int sz = 0;
	for(int i = 0; i < ord.size(); i++){
		int v = ord[i].f;
		int k = ord[i].s;
		if(was[v][k]) continue;
		id.clear();
		dfs2(v, k, sz);
		COST[sz] =id.size();
		//cout << COST[sz] << "\n";
		sz++;
	}
	for(int i = 0; i < sz; i++) DP[i] = -inf;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			for(int t = 0; t < G[i].size(); t++){
				int to = G[i][t];
				if(C[i][j] != C[to][(j+1) % d]) {
					g[C[i][j]].pb(C[to][(j+1) % d]);
				}
			}
		}
	}
	DFS(C[0][0]);
	DP[C[0][0]] = COST[C[0][0]];
	reverse(all(ORD));
	for(int i = 0; i < ORD.size(); i++){
		int v = ORD[i];
		for(int j = 0; j < g[v].size(); j++){
			int to = g[v][j];
			DP[to] = max(DP[to], DP[v] + COST[to]);
		}
	}
	cout << *max_element(DP, DP + sz) << "\n";
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}