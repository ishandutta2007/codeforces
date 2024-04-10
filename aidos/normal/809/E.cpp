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
int a[200200];
vector<int> g[200200];
vector<int> pr[200200];
int P[200200][66];
int Q[200200][66];

int inv[200200][66];
int sz[200200];
int cur[200200];
int cur2[200200];
void dfs(int v, int p){
	for(int i = 0; i < g[v].size() ;i++){
		int to = g[v][i];
		if(to == p) continue;
		dfs(to, v);
		sz[v] += sz[to];
	}
	++sz[v];
}
int mod = 1000 * 1000 * 1000 + 7;
int p = 0;
int pc[511];
ll ansA = 0;
ll ansB = 0;
int SH = 0;

void add(int x, ll deg){
	int sz = pr[x].size();
	for(int i = 0; i < (1<<sz); i++){
		int D = Q[x][i];
		cur[D] = (cur[D] + (deg - SH + mod * 1ll) % mod * 1ll * (x/Q[x][(1<<sz) - 1]) % mod * P[x][(1<<sz) - 1] % mod) % mod;
		cur2[D] = (cur2[D] +(x/Q[x][(1<<sz) - 1]) % mod * P[x][(1<<sz) - 1] % mod) % mod;
	}
}
void del(int x){
	int sz = pr[x].size();
	for(int i = 0; i < (1<<sz); i++){
		int D = Q[x][i];
		cur[D] = 0;
		cur2[D] =0;
	}
}

void S(int v, int p, int len){
	add(a[v], len);
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		S(to, v, len + 1);
	}
}
ll tmp[1111];
ll tmp2[1111];
void D(int v, int p){
	del(a[v]);
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		D(to, v);
	}
}
void comp(int v, int len){
	int x = a[v];
	int sz = pr[x].size();
	
	ll DD = (x/Q[x][(1<<sz) - 1]) * 1ll * P[x][(1<<sz) - 1]; 
	for(int i = 0 ; i < (1<<sz); i++)
		tmp[i] = tmp2[i] = 0;

	for(int mask = (1<<sz) - 1; mask >=0; --mask){
		for(int mask2 = mask; ;mask2 = (mask2 - 1) & mask){
			int pp = Q[x][mask]; 
			ll &A = tmp[mask2];
			ll &B = tmp2[mask2];
			ll D = (cur[pp] + SH * 1ll * cur2[pp] % mod) % mod;
			if(pc[mask2 ^ mask] & 1) {
				A -= D;
				if(A < 0) A += mod;
				B -= cur2[pp]% mod;
				if(B < 0) B += mod;	
			}
			else {
				A += D;
				if(A >= mod) A -= mod;
				B += cur2[pp] % mod;
				if(B >= mod) B -= mod;	
			}
			if(mask2 == 0) break;
		}
		ansA = (ansA + (tmp[mask] + tmp2[mask] * len % mod) % mod *Q[x][mask] % mod * DD % mod * inv[x][mask] % mod) % mod;
	}
}
void calc2(int v, int p, int len){
	comp(v, len);
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		calc2(to, v, len + 1);
	}
}


void calc(int v, int p, int s){
	int mx = -1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p) continue;
		if(mx == -1 || sz[mx] < sz[to]) mx = to;
	}
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == p || mx == to) continue;
		calc(to, v, 0);
	}
	
	if(mx != -1){
		calc(mx, v, 1);
		SH++;
		comp(v, 0);
		add(a[v], 0);
		for(int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if(to == p || mx == to) continue;
			calc2(to, v, 1);
			S(to, v, 1);
		}
	}
	else{
		add(a[v], 0);
	}
	if(!s){
		D(v, p);
		SH = 0;
	}
}

ll binpow(ll x, int y){
	ll res = 1;
	while(y > 0){
		if(y & 1)res = (res * 1ll * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}

void solve(){
	scanf("%d", &n);
	for(int i = 2; i <=max(n, 1000); i++){
		if(pr[i].size() == 0){
			for(int j = i; j <= max(n, 1000); j+=i)
				pr[j].pb(i);
		}
	}
	for(int i = 1; i<=max(n, 1000); i++){
		int len = pr[i].size();
		for(int mask = 0; mask < (1<<len); mask++){
			P[i][mask] = 1;
			Q[i][mask] = 1;
			for(int j = 0; j < len; j++){
				if(mask & (1<<j)) {
					P[i][mask] *= pr[i][j] - 1;
					Q[i][mask] *= pr[i][j];
				}
			}
			inv[i][mask] = binpow(P[i][mask], mod-2);
		}
	}
	for(int i = 0; i < 500; i++)
		pc[i] = __builtin_popcount(i);
	for(int i = 1; i <= n; i++){
		scanf("%d",  a + i);
	}
	for(int i = 1, u, v; i < n; i++){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	calc(1, 0, 1);
	//return;
	//cout << ansA << endl;
	cout << ansA * binpow((n * 1ll * (n - 1)/2) % mod, mod-2) % mod << endl;
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