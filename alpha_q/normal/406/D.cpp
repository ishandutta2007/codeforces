#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> point;

#define x first
#define y second

const int N = 500010;

point pt[N];
int n, m, p[N], h[N], jump[N], stk[N], top; 

inline ll area (point a, point b, point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int lca (int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  while (h[u] > h[v]) u = (h[jump[u]] < h[v]) ? p[u] : jump[u];
  while (u ^ v) (jump[u] ^ jump[v]) ? (u = jump[u], v = jump[v]) : (u = p[u], v = p[v]);
  return u;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &pt[i].x, &pt[i].y);
  }
  p[n] = -1, jump[n] = n;
  for (int i = n; i >= 1; --i) {
    while (top >= 2 and area(pt[i], pt[stk[top]], pt[stk[top - 1]]) > 0) --top;
    if (top) {
      int j = stk[top];
      p[i] = j, h[i] = h[j] + 1;
      int x = jump[j], y = jump[x];
      jump[i] = (h[j] + h[y] == h[x] << 1) ? y : j;
    }
    stk[++top] = i; 
  }
  cin >> m;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int ans = lca(u, v);
    printf("%d ", ans);
  }
  cout << '\n';
  return 0;
}