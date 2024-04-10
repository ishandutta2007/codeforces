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
const int mod = (int) 1e9 + 7;
using namespace std;
vector<pii> g[200200];
int n;
ll ans = 0;
vector<int> dfs(int v, int pa, vector<int> st, vector<int> tt, int t) {
	if(t != -1) {
		for(int i = 0; i < st.size(); i++) {
			int d = i >> 1;
			int c = i&1;
			if((d^c) == t) {
			}else if(c==1) {
				st[i] = 0;
				tt[i] = 0;
			} else {
				st[(d<<1)|1] += st[i];
				tt[(d<<1)|1] += tt[i];
				st[i] = 0;
				tt[i] = 0;
			}
		}
		st[t<<1]++;
	}
	for(int i = 0; i < st.size(); i++) {
		ans += st[i] + tt[i];
	}
	ans += tt[0] + tt[2] + st[0] + st[2];
	vector<int> CC = {0, 0, 0, 0};
	for(int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].f;
		int w = g[v][i].s;
		if(to == pa) continue;
		vector<int> gg = dfs(to, v, st, tt, w);
		gg[w<<1]++;
		for(int j = 0; j < gg.size(); j++){
			int d = j >> 1;
			int c = j&1;
			int nmask = j;
			if((d^c) == w) {
			}else if(c==1) {
				gg[j] = 0;
			}else {
				nmask ^= 1;
			}
			CC[nmask] += gg[j];
			tt[nmask] += gg[j];
		}
	}
	return CC;
}
void solve(){
	scanf("%d", &n);
	for(int i=1; i< n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		--x, --y;
		g[x].pb(mp(y, z));
		g[y].pb(mp(x, z));
	}
	dfs(0, -1, {0, 0, 0, 0}, {0, 0, 0, 0},  -1);
	cout << ans << "\n";
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