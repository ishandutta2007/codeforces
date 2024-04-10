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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
int id;
int d[2000200];
int ans[2000200];
int ID[2000200];
vector<pii> g[2000200];
void bfs(int v) {
	for(int i = 0; i < id; i++) d[i] = -1;
	d[v] = 0;
	ans[v] = 0;
	ID[v] = 0;
	queue<int> q;
	q.push(v);
	while(q.size() > 0) {
		vector<int> t;
		int u = q.front();
		while(q.size() > 0 && d[q.front()] == d[u]) {
			t.pb(q.front());
			q.pop();
		}
		vector<pair<pii, pii> > vv;
		for(int i = 0; i < t.size(); i++) {
			int v=t[i];
			for(int j = 0; j < g[v].size(); j++){
				int to = g[v][j].f;
				int sym = g[v][j].s;
				if(d[to] == -1) {
					vv.pb(mp(mp(ID[v], sym), mp(ans[v], to)));
				}
			}
		}
		sort(all(vv));
		int cc = 0;
		pair<int, int> P = mp(-1, -1);
		for(int i = 0; i < vv.size(); i++) {
			int to = vv[i].s.s;
			int val = vv[i].s.f;
			int v1 = vv[i].f.f;
			int v2 = vv[i].f.s;
			if(d[to] != -1) continue;
			if(P!=mp(v1, v2)) cc++;
			d[to] = d[u] + 1;
			ans[to] = (val*10ll + v2) % mod;
			ID[to] = cc;
			P = mp(v1, v2);
			q.push(to);
		}
	}
}
void solve(){
	scanf("%d%d", &n, &k);
	id = n+1;
	for(int i = 1; i <= k; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		string x = to_string(i);
		int pr = u;
		for(int j = 0; j+1<x.size(); j++) {
			int cur = id;
			id++;
			g[pr].pb(mp(cur, x[j]-'0'));
			pr = cur;
		}
		g[pr].pb(mp(v, x.back()-'0'));

		pr = v;
		for(int j = 0; j+1<x.size(); j++) {
			int cur = id;
			id++;
			g[pr].pb(mp(cur, x[j]-'0'));
			pr = cur;
		}
		g[pr].pb(mp(u, x.back()-'0'));
	}
	bfs(1);
	for(int i = 2; i <= n; i++) printf("%d\n", ans[i]);
}	

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}