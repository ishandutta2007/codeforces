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


string ans;
vector<int> g[300300];
vector<pair<int, int> > gg[300300];
pair<int, int> ed[300300];

int used[300300];
int used2[300300];
void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to]){
			dfs(to);
		}
	}
	for(int i = 0 ; i<gg[v].size(); i++){
		int to = gg[v][i].f;
		int ind = gg[v][i].s;
		if(!used[to]){
			if(ed[ind].f == to) ans[ind] = '-';
			dfs(to);
		}
	}
}

void dfs2(int v){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to]){
			dfs2(to);
		}
	}
	for(int i = 0 ; i<gg[v].size(); i++){
		int to = gg[v][i].f;
		int ind = gg[v][i].s;
		//if(!used[to]){
			if(ed[ind].f == v) ans[ind] = '-';
			else ans[ind] = '+';
			//dfsq(to);
		//}
	}
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	
	int cnt = 0;
	for(int i = 0, t, a, b; i < m; i++){
		scanf("%d%d%d", &t, &a, &b);
		if( t == 1 ){
			g[a].pb(b);
		}
		else{
			gg[b].pb(mp(a, cnt));
			gg[a].pb(mp(b, cnt));
			ed[cnt] = mp(a, b);
			cnt++;
			ans+='+';
		}
	}
	dfs(s);
	int aa = 0;
	for(int i = 1; i <= n; i++){
		aa += used[i];
		used[i] = 0;
	}
	printf("%d\n%s\n", aa, ans.c_str());
	
	dfs2(s);
	aa = 0;
	for(int i = 1; i <= n; i++){
		aa += used[i];
		used[i] = 0;
	}
	printf("%d\n%s\n", aa, ans.c_str());
	
	

	return 0;
}