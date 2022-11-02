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

int n;
vector<int> g[300100];
int d[300100];
int used[300100];
pii a[300300];
vector<int> ans;

void change(int v){
	if(d[v] == -1) return;
	d[v] ^= 1;
}

void dfs(int v, int p){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int ind = g[v][i];
		int to = a[ind].f ^ v ^ a[ind].s;
		if(used[to]) continue;
		dfs(to, v);
		if(d[to] == 1){
			d[to] ^= 1;
			change(v);
			ans.pb(ind);
		}
	}

}
int m;
void solve(){
	scanf("%d%d", &n, &m);
	int v=-1;
	for(int i = 1;i <= n; i++){
		scanf("%d", &d[i]);
		if(d[i] == -1) v = i;
	}
	if(v == -1) v = 1;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &a[i].f, &a[i].s);
		g[a[i].f].pb(i);
		g[a[i].s].pb(i);
	}
	dfs(v, 0);
	if(d[v] != -1 && d[v] == 1){
		cout << -1 << endl;
		return;
	}
	printf("%d\n", (int)ans.size());
	for(int i=0; i < ans.size(); i++){
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}