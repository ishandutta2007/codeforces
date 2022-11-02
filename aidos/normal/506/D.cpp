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
int n, m, q;
int used[100100];
int T;

vector<pii> g[100100];
vector<int> gg[100100];
vector <int> col;
vector <int>comp[100100];

int sz = 0;


void dfs(int v, int com){
	comp[com].pb(v);
	used[v] = T;
	for(int i = 0; i < gg[v].size(); i++){
		int to = gg[v][i];
		if(used[to] != T){
			dfs(to, com);
		}
	}
}

const int bl = 300;

void solve(){
	scanf("%d %d", &n, &m);
	for(int i =0, a, b, c; i < m; i++){
		scanf("%d %d %d",&a, &b, &c);
		g[c].pb(mp(a, b));
	}
	for(int i = 1; i <= m; i++){
		if(g[i].size() == 0) continue;
		T++;
		col.clear();
		for(int j = 0; j < g[i].size(); j++){
			int v = g[i][j].f;
			int u = g[i][j].s;
			col.pb(v);
			col.pb(u);
			gg[u].pb(v);
			gg[v].pb(u);
		}
		for(int j = 0; j < col.size(); j++){
			int v = col[j];
			if(used[v] != T){
				dfs(v, sz);
				sz++;
			}
		}
		for(int j = 0; j < col.size(); j++){
			gg[col[j]].clear();
		}
	}
	vector<int> x;
	map <pii, int> mm;
	for(int i = 0; i < sz; i++){
		if(comp[i].size()> bl){
			sort(all(comp[i]));
			x.pb(i);
		}else{
			for(int j = 0; j <comp[i].size();j++){
				int u = comp[i][j];
				for(int k = j+1; k < comp[i].size(); k++){
					int v = comp[i][k];
					mm[mp(u, v)]++;
					mm[mp(v, u)]++;
				}
			}
		}
	}
	scanf("%d", &q);
	for(int i = 0, a, b; i < q; i++){
		scanf("%d %d", &a,&b);
		int ans = mm[mp(a, b)];
		for(int j = 0; j < x.size(); j++){
			int ind = x[j];
			int l1 = lower_bound(all(comp[ind]), a) - comp[ind].begin();
			int l2 = lower_bound(all(comp[ind]), b) - comp[ind].begin();
			if(l1 < comp[ind].size() && comp[ind][l1] == a){
				if(l2 < comp[ind].size() && comp[ind][l2] == b){
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
		
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}