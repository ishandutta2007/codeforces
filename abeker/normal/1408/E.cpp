#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Edge {
  int a, b, c;
  bool operator <(const Edge &rhs) const {
    return c > rhs.c;
  }
};

int M, N;
int a[MAXN], b[MAXN];
int dad[MAXN], rnk[MAXN];

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

bool join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return false;
  if (rnk[x] > rnk[y])
    swap(x, y);
  dad[x] = y;
  rnk[y] += rnk[x] == rnk[y];
  return true;
}

int main() {
  scanf("%d%d", &M, &N);
  for (int i = 1; i <= M; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
  
  long long ans = 0;
  vector <Edge> edges;
  for (int i = 1; i <= M; i++) {
    int sz;
    scanf("%d", &sz);
    while (sz--) {
      int elem;
      scanf("%d", &elem);
      edges.push_back({i, elem + M, a[i] + b[elem]});
      ans += edges.back().c;
    }
  }
  
  sort(edges.begin(), edges.end());
  
  iota(dad + 1, dad + M + N + 1, 1);
  for (auto it : edges)
    if (join(it.a, it.b))
      ans -= it.c;
  
  printf("%lld\n", ans);
  
  return 0;
}