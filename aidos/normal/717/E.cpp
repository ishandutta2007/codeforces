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
#include<cassert>
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
#define prev asdfasdfadfasdfzsdfasdf

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


vector<int> g[200100];

int col[200100];

vector<int> ans;
int n;

void dfs(int v, int p){
	col[v] ^= 1;
	ans.pb(v);
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		ans.pb(v);
		col[v] ^= 1;
	}
	if(col[v] == 0 && p != 0){
		ans.pb(p);
		ans.pb(v);
		col[p] ^= 1;
		col[v] ^= 1;
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 1, x; i <= n; i++){
		scanf("%d", &x);
		if(x==-1) col[i] = 0;
		else col[i] = 1;	
	}
	for(int i = 1, a, b; i < n; i++){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	if(col[1] == 1){
		ans.pb(g[1].back());
		ans.pb(1);
		ans.pb(g[1].back());
	}
	//printf("%d\n" ,ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}