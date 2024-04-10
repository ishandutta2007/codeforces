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

int nxt[2000100][27];
int link[2000100];
char c[1000100];
int good[2000100];
vector<int> g[2000100];
int sz;
int len;
int ind1[1000100];
int ind2[1000100];
int n;
void clr(int g){
	good[g] = 0;
	link[g] = 0;
	for(int i = 0; i < 26; i++)
		nxt[g][i] = 0;
}

void add(int st, int d){
	int v = 0;
	for(int i = st; i < len; i++){
		int sym = c[i] - 'a';
		if(!nxt[v][sym]){
			clr(sz);
			nxt[v][sym] = sz;
			sz++;
		}
		v = nxt[v][sym];
		good[v] |= d;
	}
}

void go(int ind[], int st){
	int v = 0;
	int g = 0;
	for(int i = st; i < len; i++){
		int sym = c[i] - 'a';
		v = nxt[v][sym];
		ind[g] = v;
		g++;
	}	
}

int id[2000100];
int gg;
int par[2000100];

bool used[2000100];

int dfs(int v){
	if(used[v]) return 0;
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(par[to] == -1){
			par[to] = v;
			par[v] = to;
			return 1;
		}
		if(dfs(par[to])){
			par[v] = to;
			par[to] = v;
			return 1;
		}
	}
	return 0;
}

void solve(){
	scanf("%d", &n);
	sz = 1;
	clr(0);
	for(int i = 0; i < n; i++){
		scanf("%s", c);
		len = strlen(c);
		add(1, 0);
		go(ind2, 1);
		add(0, 1);
		go(ind1, 0);
		for(int j = 1; j < len; j++)
			link[ind1[j]] = ind2[j-1];
	}
	gg = 0;
	for(int i = 1; i < sz; i++){
		if(good[i]){
			id[i] = gg;
			gg++;
		}
	}
	for(int i=1; i < sz; i++){
		if(good[i]){
			if(good[link[i]]){
				int u = id[i];
				int v = id[link[i]];
				g[u].pb(v);
				g[v].pb(u);
			}
		}
	}
	for(int i = 0; i < gg; i++){
		par[i] = -1;
	}
	for( int run = 1; run; ){
		run = 0;
		for(int i = 0; i < gg; i++)
			used[i] = 0;
		for(int i = 0; i < gg; i++){
			if(par[i] == -1&& dfs(i)){
				run = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < gg; i++){
		if(par[i] != -1){
			cnt++;
		}
	}
	printf("%d\n", gg - cnt/2);


	for(int i = 0; i < sz; i++){
		g[i].clear();
	}
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}