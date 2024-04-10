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

vector<pii> g[100100];
vector<pii> gr[100100];
bool dp[111][111][300];

bool used[111][111][300];
int n;
int m;
vector<int> reb;
int get(int u, int v, int c){
	if(used[u][v][c]) return dp[u][v][c];
	bool &res = dp[u][v][c];
	used[u][v][c] = 1;
	res=  0;
	for(int i = 0; i < g[u].size(); i++){
		int sym = g[u][i].s;
		int d = lower_bound(all(reb), sym) - reb.begin();
		//cout << endl;
		//cout << sym << " "<< d << endl;
		if(d >= c){
			res = max(res, !get(v, g[u][i].f, d));
		}
	}
	return res;
}
void solve(){
	cin >> n >> m;
	set<int> S;
	for(int i = 0, u, v; i < m; i++){
		char c;
		cin >> u >> v >> c;
		g[u].pb(mp(v, c));
		S.insert(c);
	}
	S.insert(-1);
	forit(it, S) reb.pb(*it);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(get(i, j, 0)){
				printf("A");
			}
			else printf("B");
		}
		printf("\n");
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