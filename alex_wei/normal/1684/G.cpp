//#pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
 	#define gc getchar()
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
}
using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}

const int N = 1e3 + 5;
const int M = N * N; 
int n, m, t[N];
struct flow {
  int cnt = 1, hd[N], nxt[M << 1], to[M << 1], limit[M << 1];
  void add(int u, int v, int w) {
    nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, limit[cnt] = w;
    nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, limit[cnt] = 0;
  }
  int T, cur[N], dis[N];
  int dfs(int id, int res = 1064) {
    if(id == T) return res;
    int flow = 0;
    for(int i = cur[id]; i && res; i = nxt[i]) {
      cur[id] = i;
      int it = to[i], c = min(limit[i], res);
      if(dis[id] + 1 == dis[it] && c) {
        int k = dfs(it, c);
        flow += k, res -= k, limit[i] -= k, limit[i ^ 1] += k;
      }
    }
    if(!flow) dis[id] = -1;
    return flow;
  }
  int maxflow(int s, int t) {
    T = t;
    int flow = 0;
    while(1) {
      queue<int> q;
      memset(dis, -1, sizeof(dis));
      memcpy(cur, hd, sizeof(hd));
      q.push(s), dis[s] = 0;
      while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = hd[t]; i; i = nxt[i])
          if(limit[i] && dis[to[i]] == -1)
            dis[to[i]] = dis[t] + 1, q.push(to[i]);
      }
      if(dis[t] == -1) return flow;
      flow += dfs(s);
    }
  }
} g;
int l;
bool vis[N];
vector<pair<int, int>> ans;
int main() {
	cin >> n >> m;
	for(int i = 1, v; i <= n; i++) cin >> t[i];
	sort(t + 1, t + n + 1);
	if(t[n] * 2 >= m) return puts("-1"), 0;
	for(int i = 1; i <= n; i++) if(t[i] * 3 <= m) l++;
	for(int i = l + 1; i <= n; i++) g.add(0, i, 1);
	for(int i = 1; i <= l; i++) g.add(i, n + 1, 1);
	for(int i = l + 1; i <= n; i++)
		for(int j = 1; j <= l; j++)
			if(t[i] % t[j] == 0 && 2ll * t[i] + t[j] <= m)
				g.add(i, j, 1);
	if(g.maxflow(0, n + 1) != n - l) return puts("-1"), 0;
	for(int i = l + 1; i <= n; i++)
		for(int j = g.hd[i]; j; j = g.nxt[j]) {
			int it = g.to[j];
			if(it >= 1 && it <= l && !g.limit[j]) vis[it] = 1, ans.push_back({2 * t[i] + t[it], t[i] + t[it]});
		}
	for(int i = 1; i <= l; i++) if(!vis[i]) ans.push_back({3 * t[i], 2 * t[i]});
	cout << ans.size() << endl;
	for(auto it : ans) cout << it.first << " " << it.second << endl;
	return 0;
}
/*
 3x <= m  
*/