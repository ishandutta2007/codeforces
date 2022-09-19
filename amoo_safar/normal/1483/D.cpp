// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 600 + 10;
const int Inf = 1000001000;
const ll Log = 30;

int f[N][N];
int g[N][N];

int gd[N][N], fly[N][N];
int mk[N], dis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(f, -1, sizeof f);
	for(int i = 0; i < N; i++) fill(g[i], g[i] + N, Inf);
	for(int i = 0; i < N; i++) fill(fly[i], fly[i] + N, Inf);
	
	int n, m;
	cin >> n >> m;

	int u, v, w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
		fly[u][v] = fly[v][u] = w;
	}
	for(int i = 1; i <= n; i++) fly[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				fly[i][j] = min(fly[i][j], fly[i][k] + fly[k][j]);

	int q, l;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> u >> v >> l;
		f[u][v] = max(f[u][v], l);
		f[v][u] = max(f[v][u], l);
	}

	for(int fs = 1; fs <= n; fs ++){
		for(int i = 1; i <= n; i++) mk[i] = 0, dis[i] = f[fs][i];
		int idx;
		while(true){
			idx = -1;
			for(int i = 1; i <= n; i++){
				if(mk[i]) continue;
				if(dis[i] < 0) continue;

				if(idx == -1) idx = i;
				if(dis[i] > dis[idx]) idx = i;
			}
			if(idx == -1) break;
			mk[idx] = 1;
			for(int adj = 1; adj <= n; adj ++){
				dis[adj] = max(dis[adj], dis[idx] - g[idx][adj]);
			}
		}
		// if(fs == 1){
		// 	cerr << "!! ";
		// 	for(int kk = 1; kk <= n; kk++)cerr << dis[kk] << ' ';
		// 	cerr << '\n';
		// }
		for(int e1 = 1; e1 <= n; e1 ++){
			for(int e2 = 1; e2 <= n; e2 ++){
				if(e1 == e2) continue;
				if(fly[fs][e1] + g[e1][e2] <= dis[e2]){
					gd[e1][e2] = 1;
					// cerr << "&&& " << fly[fs][e1] << ' ' << g[e1][e2] << ' ' << dis[e2] << '\n';
				}
			}
		}
	}
	int ans = 0;

	for(int e1 = 1; e1 <= n; e1 ++){
		for(int e2 = e1 + 1; e2 <= n; e2 ++){
			if(gd[e1][e2] == 1 || gd[e2][e1] == 1){
				ans ++;
				// debug(g[e1][e2]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}