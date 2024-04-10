#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define pii pair<int, int>


int n, m, k;
int used[200200];
vector<int> g[200100];

vector<int> gg[200100];
int l[200200];
int r[200200];

vector<int> ord;

void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to]) dfs(to);
	}
	ord.pb(v);
}

vector<int> op[200200];
vector<int> cl[200200];

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, x; i <= n; i++){
		scanf("%d", &x);
		if(x == 0){
			l[i] = 1;
			r[i] = k;
		}
		else{
			l[i] = x;
			r[i] = x;
		}
	}
	for(int i = 0, a, b; i < m; i++){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		gg[b].pb(a);
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			dfs(i);
		}
	}
	reverse(all(ord));
	for(int i = 0; i < n; i++){
		int v = ord[i];
		for(int j = 0; j < g[v].size(); j++){
			int to = g[v][j];
			r[to] = min(r[to], r[v] - 1);
		}
	}
	reverse(all(ord));
	for(int i = 0; i < n; i++){
		int v = ord[i];
		for(int j = 0; j < gg[v].size(); j++){
			int to = gg[v][j];
			l[to] = max(l[to], l[v] + 1);
		}
	}
	vector< pair<pii, int> > cur;
	for(int i = 1; i <= n; i++){
		if(l[i] > r[i]){
			printf("-1\n");
			return 0;
		}
		op[l[i]].pb(i);
		cl[r[i]].pb(i);
	}
	int sz = 0;
	set<pii> S;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < op[i].size(); j++){
			int t = op[i][j];
			S.insert(mp(r[t], t));
		}
		if(S.size() == 0) {
			cout << -1 << endl;
			return 0;
		}
      r[S.begin()->s] = i;
      S.erase(S.begin());
      for(int j = 0; j < cl[i].size(); j++){
			int t = cl[i][j];
			S.erase(mp(r[t], t));
		}
	}
	for(int i = 1; i <= n; i++){
		if(i > 1) printf(" ");
		printf("%d", r[i]);
	} 
	printf("\n");


	return 0;
}