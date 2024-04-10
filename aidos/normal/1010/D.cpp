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
vector<int> g[1001000];
vector<int> A[1001000];
int d[1001000];
string tmp;

int dfs(int v){
	if(d[v] < 2) return d[v];
	if(d[v] == 5){
		A[v].pb(!dfs(g[v][0]));
		return A[v][0];
	}
	A[v].pb(dfs(g[v][0]));
	A[v].pb(dfs(g[v][1]));
	if(d[v] == 2) return A[v][0]^A[v][1];
	if(d[v] == 3) return A[v][0] & A[v][1];
	if(d[v] == 4) return A[v][0]|A[v][1];
	//assert(false);
}
vector<pair<int, int> > ans;

int get_res(int ty, int i, int j){
	if(ty == 2) return i^j;
	if(ty == 3) return i&j;
	return i|j;
}
void dfs2(int v, int c1, int c2){
	if(d[v] < 2){
		if(d[v] == 0) ans.pb(mp(v, c2));
		else ans.pb(mp(v, c1));
		return;
	}
	if(d[v] == 5){
		dfs2(g[v][0], c2, c1);
		return;
	}
	
	for(int i = 0; i < 2; i++){
		int dd[2] = {c1, c2};
		int res[2] = {0, 0};
		for(int j = 0; j < 2; j++){
			res[j] = dd[get_res(d[v], j, A[v][i^1])];
		}
		dfs2(g[v][i], res[0], res[1]);
	}
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> tmp;
		if(tmp == "XOR"){
			int u, v;
			cin >> u >> v;
			d[i] = 2;
			g[i].pb(u);
			g[i].pb(v);
		}else if(tmp == "IN"){
			int v;
			cin >> v;
			d[i] = v;
		}else if(tmp == "AND"){
			int u, v;
			cin >> u >> v;
			d[i] = 3;
			g[i].pb(u);
			g[i].pb(v);
		}else if(tmp == "OR"){
			int u, v;
			cin >> u >> v;
			d[i] = 4;
			g[i].pb(u);
			g[i].pb(v);
		}else if(tmp == "NOT"){
			int u;
			cin>>u;
			d[i] = 5;
			g[i].pb(u);
		}
	}
	dfs(1);
	dfs2(1, 0, 1);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout<<ans[i].s;
	}
	cout << "\n";
}

int main () {
	ios_base::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}