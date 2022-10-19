#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
vector <int> E[MAXN];
int leaves;

void load() {
   scanf("%d", &N);
   for (int i = 1; i < N; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      E[a].push_back(b);
      E[b].push_back(a);
   }
}

pii dfs(int x, int p, int d) {
   bool leaf = true;
   int mini[2] = {N, N};
   int sum[2] = {0, 0};
   for (int i = 0; i < E[x].size(); i++) {
      int nxt = E[x][i];
      if (nxt == p) continue;
      leaf = false;
      pii curr = dfs(nxt, x, d ^ 1);
      mini[0] = min(mini[0], curr.first);
      mini[1] = min(mini[1], curr.second);
      sum[0] += curr.first;
      sum[1] += curr.second;
   }
   leaves += leaf;
   if (leaf) return pii(1, 1);
   if (d) return pii(sum[0], mini[1]);
   return pii(mini[0], sum[1]);
}

void solve() {
   pii sol = dfs(1, 0, 0);
   printf("%d %d\n", leaves + 1 - sol.first, sol.second);
}

int main() {
   load();
   solve();
   return 0;
}