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
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 2e2 + 10;
const int Inf = 1e5;
const ll Log = 30;

int c[N][N];
int f[N][N], n, m;
vector<pii> E[N];
vector<int> G[N];

int par[N];
queue<int> q;

ll ans = 0;

void MaxFlow(int s, int t){
	memset(f, 0, sizeof f);
	int fr;
	while(true){
		memset(par, -1, sizeof par);
		q.push(s);
		while(!q.empty()){
			fr = q.front(); q.pop();
			for(int adj = 0; adj <= n + n + 1; adj ++){
				if(((f[fr][adj] < c[fr][adj]) || (f[adj][fr] > 0)) && par[adj] == -1){
					q.push(adj);
					par[adj] = fr;
				}
			}
		}
		if(par[t] == -1) break;
		ans ++;
		int nw = t;
		while(nw != s){
			if(f[nw][par[nw]]) f[nw][par[nw]] --;
			else f[par[nw]][nw] ++;
			nw = par[nw];
		}
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int u, v;
	int sa = 0, sb = 0;
	for(int i = 1; i <= n; i++){
		cin >> v;
		c[0][i << 1] = v;
		sa += v;
	}
	for(int i = 1; i <= n; i++){
		cin >> v;
		c[i << 1 | 1][1] = v;
		sb += v;
	}
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u *= 2; v *= 2;
		c[u][v ^ 1] = Inf;
		c[v][u ^ 1] = Inf;
	}
	for(int i = 1; i <= n; i++){
		c[i << 1][i << 1 | 1] = Inf;
	}
	MaxFlow(0, 1);
	
	if(ans != sa || ans != sb) return cout << "NO\n", 0;
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cout << f[i << 1][j << 1 | 1] << " \n"[j == n];
	return 0;
}