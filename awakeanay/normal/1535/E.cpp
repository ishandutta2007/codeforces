#include <iostream>

#define int long long

const int LOG = 20;
const int MAXN = 300005;

int par[LOG][MAXN];
int a[MAXN], c[MAXN];

// get kth ancestor of x
int get(int x, int k) {
  int v = x;
  for(int i = LOG-1; i >= 0; i--) {
    if(k >= (1 << i)) {
      v = par[i][v];
      k -= (1 << i);
    }
  }
  return v;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int q;
  std::cin >> q;

  std::cin >> a[0] >> c[0];
  for(int j = 0; j < LOG; j++)
    par[j][0] = -1;

  for(int i = 1; i <= q; i++) {
    int t;
    std::cin >> t;

    if(t == 1) {
      std::cin >> par[0][i] >> a[i] >> c[i];
      for(int j = 1; j < LOG; j++) {
        if(par[j-1][i] == -1)
          par[j][i] = -1;
        else
          par[j][i] = par[j-1][par[j-1][i]];
      }
    }
    else {
      int v, w;
      std::cin >> v >> w;

      if(a[v] == 0) {
        std::cout << 0 << " " << 0 << std::endl;
        continue;
      }

      int first = v, dist = 0;
      for(int j = LOG-1; j >= 0; j--) {
        if(par[j][first] != -1 && a[par[j][first]] > 0) {
          dist += (1 << j);
          first = par[j][first];
        }
      }

      int amt = 0, cost = 0;
      while(w > 0) {
        int cur = get(v, dist);
        int buy = std::min(w, a[cur]);
        a[cur] -= buy;
        cost += buy*c[cur];
        w -= buy;
        amt += buy;
        if(dist == 0)
          break;
        dist--;
      }

      std::cout << amt << " " << cost << std::endl;
    }
  }

  return 0;
}