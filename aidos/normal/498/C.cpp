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
int n, m;
int f[111][111];
int c[111][111];
int u[111];
int a[111];
pii P[111];
int dfs(int v, int flow) {
	if(v == n + 1) {
		return flow;
	}
	if(!flow) return 0;
	if(u[v]) return 0;
	u[v] = 1;
	for(int i = 0; i <= n + 1; i++) {
		int cur = dfs(i, min(flow, c[v][i] - f[v][i]));
		if(cur) {
			f[v][i] += cur;
			f[i][v] -= cur;
			return cur;
		}
	}
	return 0;
}
int max_flow(int pr) {
	//cout << pr << "\n";
	memset(c, 0, sizeof c);
	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; i++) {
		int d = 0;
		while(a[i] % pr == 0) {
			a[i] /= pr;
			d++;
		}
		if(i % 2) c[0][i] = d;
		else c[i][n+1] = d;
	}
	for(int i = 0; i < m;i++) {
		c[P[i].f][P[i].s] = inf;
	}
	int g = 1, ans = -1;
	while(g) {
		ans += g;	
		memset(u, 0, sizeof u);
		g = dfs(0, inf);
	}
	return ans;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		cin>>P[i].f >> P[i].s;
		if(P[i].s % 2) swap(P[i].f, P[i].s);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int j = 2;
		while(j * j <= a[i]) {
			if(a[i] % j == 0) ans += max_flow(j);
			j += 1;
		}
		if(a[i] > 1) ans += max_flow(a[i]);
	}
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