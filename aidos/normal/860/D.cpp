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

std::vector<int> g[200200];
int used[200200];
int n;
int m;
std::vector<pair<int, pii > > ans;

int dfs(int v, int p){
	used[v] = 1;
	vector<int> li;
	for(int i = 0; i < g[v].size(); i++){
		int to =g[v][i];
		if(used[to]){
			if(used[to] == 2) li.pb(to);
		}
		else if(dfs(to, v)) {
			li.pb(to);
		}
	}
	int ad = 1;
	if(li.size() % 2 == 1 && p > 0){
		li.pb(p);
		ad = 0;
	}
	for(int i = 1; i < li.size(); i+=2){
		ans.pb(mp(li[i-1], mp(v, li[i])));
	}
	used[v] = 2;
	return ad;
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i = 1; i <= n; i++){
		if(used[i]) continue;
		dfs(i, 0);
	}
	printf("%d\n", (int) ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d %d %d\n", ans[i].f, ans[i].s.f, ans[i].s.s);
	}
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