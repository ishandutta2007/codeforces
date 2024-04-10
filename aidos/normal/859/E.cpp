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

const int mod = 1000 * 1000*1000 + 7;

int n;
pii a[200100];
std::vector<int> g[200200];
std::vector<int> gr[200200];
set<int> S, ba, cyc;
int t[200200];
int used[200200];
int timer=1;

std::vector<int> comp;

void dfs(int v){
	used[v] = 1;
	comp.pb(v);
	forit(it, g[v]){
		if(!used[*it]){
			dfs(*it);
		}
	}

	forit(it, gr[v]){
		if(!used[*it]){
			dfs(*it);
		}
	}
}
int ans;
std::vector<int> li;

void calc(){

	int ind = 0;
	for(int i = 0; i < comp.size(); i++){
		int to = comp[i];
		if(g[to].size() == 0){
			ind = to;
		}
	}
	if(!ind){
		ans = (ans * 2) % mod;
		return;
	}
	ans = ans *1ll * comp.size() % mod;
}


void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i].f, &a[i].s);
		if(a[i].f==a[i].s) ba.insert(a[i].s);
		gr[a[i].s].pb(a[i].f);
		g[a[i].f].pb(a[i].s);
		S.insert(a[i].f);
		S.insert(a[i].s);
	}
	ans = 1;
	forit(it, ba){
		comp.clear();
		dfs(*it);
	}
	forit(it, S){
		if(!used[*it]){
			comp.clear();
			dfs(*it);
			calc();
		}
	}
	cout << ans << endl;
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