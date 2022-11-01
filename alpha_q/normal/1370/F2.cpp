#include <bits/stdc++.h>

using namespace std;

const int N = 1069;

char tmp[69];
bitset <N> bad;
int t, n, h[N], mx, par[N];
vector <int> g[N], deep[N];

void go (int u, int pr = -1, int far = 0) {
  h[u] = far, par[u] = pr, deep[far].emplace_back(u), mx = max(mx, far);
  for (int v : g[u]) if (v ^ pr) go(v, u, far + 1);
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
      g[i].clear(), deep[i].clear(), bad[i] = 0;
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v), g[v].emplace_back(u);
    }
    printf("? %d", n);
    for (int i = 1; i <= n; ++i) printf(" %d", i);
    puts(""); fflush(stdout);
    int root, len, one, two, u, d, dist; 
    scanf("%d %d", &root, &len);
    mx = 0, one = root; go(root);  
    int lo = (len >> 1) - 1, hi = min(mx, len);
    while (lo < hi) {
      int mid = lo + hi + 1 >> 1, sz = deep[mid].size();
      printf("? %d", sz);
      for (int x : deep[mid]) printf(" %d", x);
      puts(""); fflush(stdout);
      scanf("%d %d", &u, &d);
      if (d > len) hi = mid - 1;
      else one = u, dist = d, lo = mid;
    }
    int oth = len - h[one], at = one;
    while (at != root) bad[at] = 1, at = par[at];
    if (oth) {
      vector <int> now;
      for (int x : deep[oth]) if (!bad[x]) now.emplace_back(x);
      if (now.size() == 1) two = now[0];
      else {
        printf("? %d", (int) now.size());
        for (int x : now) printf(" %d", x);
        puts(""); fflush(stdout);
        scanf("%d %d", &two, &d);
      }
    } else {
      two = root;
    }
    printf("! %d %d\n", one, two);
    fflush(stdout); scanf("%s", tmp); assert(tmp[0] == 'C');
  }
  return 0;
}