/*


 
*/
#include <bits/stdc++.h>
const int N = 505, inf = 0x3f3f3f3f;
using std::pair;
namespace QS {
 int n, s, t, S, T, cnt, h[N], cur[N], in[N], dis[N], maxflow, mincost;
 bool vis[N];
 struct Edge {
  int lac, flow, w, to;
  void insert(int x, int y, int z, int W) {
   lac = h[x];
   to = y;
   w = W;
   flow = z;
   h[x] = cnt++;
  }
 } edge[N * N];
 void init(int ops) {
  n = ops;
  s = 0;
  t = n + 1;
  S = t + 1;
  T = S + 1;
  memset(h, -1, sizeof h);
  return;
 }
 inline void Add_Edge(int w, int up, int low, int v, int u) {
  in[u] -= low;
  in[v] += low;
  edge[cnt].insert(u, v, up - low, w);
  edge[cnt].insert(v, u, 0, -w);
  return;
 }
 inline void Add_Edge(int w, int flow, int v, int u) {
  edge[cnt].insert(u, v, flow, w);
  edge[cnt].insert(v, u, 0, -w);
  return;
 }
 int Dfs(int u, int sum) {
  if (u == T)
   return sum;
  int min = sum;
  vis[u] = 1;
  for (int i = cur[u], to; ~i; i = edge[i].lac) {
   cur[u] = i;
   if (edge[i].flow && dis[to = edge[i].to] == dis[u] + edge[i].w && !vis[to]) {
    int ret = Dfs(to, std::min(min, edge[i].flow));
    min -= ret;
    edge[i].flow -= ret;
    edge[i ^ 1].flow += ret;
    if (!min)
     break;
   }
  }
  vis[u] = 0;
  return sum - min;
 }
 bool spfa() {
  memset(dis, 63, sizeof dis);
  dis[S] = 0;
  std::queue<int> Q;
  Q.push(S);
  while (!Q.empty()) {
   int fr = Q.front();
   Q.pop();
   vis[fr] = 0;
   for (int i = h[fr], to; ~i; i = edge[i].lac) {
    if (edge[i].flow && dis[(to = edge[i].to)] > dis[fr] + edge[i].w) {
     dis[to] = dis[fr] + edge[i].w;
     if (!vis[to])
      Q.push(to),
      vis[to] = 1;
    }
   }
  }
  return dis[T] != inf;
 }
 pair<int, int> Dinitz() {
  maxflow = 0, mincost = 0;
  while (spfa()) {
   memcpy(cur, h, sizeof cur);
   int flow = Dfs(S, inf);
   mincost += flow * dis[T];
   maxflow += flow;
  }
  return std::make_pair(maxflow, mincost);
 }
};
int n1, n2, m, R, B;
char c1[N], c2[N];
int main() {
 scanf("%d %d %d %d %d", &n1, &n2, &m, &R, &B);
 QS::init(n1 + n2);
 scanf("%s %s", c1 + 1, c2 + 1);
 int x, y;
 for (int i = 1; i <= m; ++i) {
  scanf("%d %d", &x, &y);
  QS::Add_Edge(R, 1, 0, y + n1, x);
  QS::Add_Edge(B, 1, 0, x, y + n1);
 }
 for (int i = 1; i <= n1; ++i) {
  if (c1[i] == 'R')
   QS::Add_Edge(0, inf, 1, i, QS::s);
  if (c1[i] == 'B')
   QS::Add_Edge(0, inf, 1, QS::t, i);
  if (c1[i] == 'U')
   QS::Add_Edge(0, inf, 0, i, QS::s),
   QS::Add_Edge(0, inf, 0, QS::t, i);
 }
 for (int i = 1; i <= n2; ++i) {
  if (c2[i] == 'B')
   QS::Add_Edge(0, inf, 1, i + n1, QS::s);
  if (c2[i] == 'R')
   QS::Add_Edge(0, inf, 1, QS::t, i + n1);
  if (c2[i] == 'U')
   QS::Add_Edge(0, inf, 0, i + n1, QS::s),
   QS::Add_Edge(0, inf, 0, QS::t, i + n1);
 }
 QS::Add_Edge(0, inf, 0, QS::s, QS::t);
 int sum = 0;
 for (int i = QS::s; i <= QS::t; ++i)
  if (QS::in[i] > 0)
   sum += QS::in[i],
   QS::Add_Edge(0, QS::in[i], 0, i, QS::S);
  else
   QS::Add_Edge(0, -QS::in[i], 0, QS::T, i);
 pair<int, int> res = QS::Dinitz();
 if (res.first ^ sum)
  return puts("-1"), 0;
 printf("%d\n", res.second);
 for (int i = 0; i < 4 * m; i += 4) {
  if (!QS::edge[i].flow)
   putchar('R');
  else if (!QS::edge[i + 2].flow)
   putchar('B');
  else
   putchar('U');
 }
 return 0;
}