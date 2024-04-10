#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int d, s;
int E[2510050][10];

int Get(int x, int y) { return x * d + y;}
int dis[2710500];
char ok[2700050] = {};
vector <int> ans;
int ST, EN;

int dfs(int x) {
	if(x == EN) return 1;
	ok[x] = 1;
	rep(u, 10) if(x != 0 || u != 0) {
		int v = E[x][u];
		if(dis[v] == dis[x] + 1 && ok[v] == 0) {
			ans.pb(u);
			if(dfs(v)) return 1;
			ans.pop_back();
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &d, &s);
	for(int i=0;i<=s;i++) for(int j=0;j<d;j++) {
		int x = Get(i, j);
		rep(e, 10) {
			if(i == 0 && j == 0 && e == 0) continue;
			int ni = i + e;
			int nj = (10 * j + e) % d;
			if(ni <= s) {
				int xx = Get(ni, nj);
				E[x][e] = xx;
			}
		}
	}
	ST = Get(0, 0), EN = Get(s, 0);
	vector <int> v; v.pb(ST);
	memset(dis, -1, sizeof dis);
	dis[ST] = 0;
	rep(i, szz(v)) {
		int t = v[i];
		rep(u, 10) if(t != 0 || u != 0) {
			int w = E[t][u];
			if(dis[w] == -1) {
				dis[w] = dis[t] + 1;
				v.pb(w);
			}
		}
	}
	if(dis[EN] == -1) puts("-1");
	else {
		dfs(ST);
		for(int e: ans) printf("%d", e); puts("");
	}
}