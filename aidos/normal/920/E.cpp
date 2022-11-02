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
set<int> S;
vector<int> g[200200];
int n, m;
int used[200200];

int dfs(int v){
	S.erase(v);
	used[v] = 1;
	int cnt = 1;
	int last = 0;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		int bad = 0;
		while(!bad){
			set<int> :: iterator it = S.upper_bound(last);
			if(*it < to){
				int x = *it;
				cnt += dfs(x);
			}
			else {
				bad = 1;
			}
		}
		last = to;
	}
	
	return cnt;
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0, x, y; i < m; i++){
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i = 1; i <= n; i++){
		g[i].pb(inf);
		sort(all(g[i]));
		S.insert(i);
	}
	S.insert(inf);
	vector<int> ans;
	for(int i = 1; i <= n; i++){
		if(used[i]) continue;
		ans.pb(dfs(i));
	}
	sort(all(ans));
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d%c", ans[i], " \n"[i+1 == ans.size()]);
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