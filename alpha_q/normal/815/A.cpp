#include <bits/stdc++.h> 

using namespace std;

const int N = 105;

int n, m, g[N][N], h[N][N];
vector <string> a, c;
vector <int> b, d; 

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", g[i] + j);
      h[i][j] = g[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    int mn = g[i][1];
    for (int j = 1; j <= m; ++j) {
      mn = min(mn, g[i][j]);
    }
    for (int j = 1; j <= m; ++j) {
      g[i][j] -= mn;
    }
    for (int j = 0; j < mn; ++j) {
      a.push_back("row");
      b.push_back(i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int mn = g[1][i];
    for (int j = 1; j <= n; ++j) {
      mn = min(mn, g[j][i]);
    }
    for (int j = 1; j <= n; ++j) {
      g[j][i] -= mn;
    }
    for (int j = 0; j < mn; ++j) {
      a.push_back("col");
      b.push_back(i);
    }
  }


  for (int i = 1; i <= m; ++i) {
    int mn = h[1][i];
    for (int j = 1; j <= n; ++j) {
      mn = min(mn, h[j][i]);
    }
    for (int j = 1; j <= n; ++j) {
      h[j][i] -= mn;
    }
    for (int j = 0; j < mn; ++j) {
      c.push_back("col");
      d.push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int mn = h[i][1];
    for (int j = 1; j <= m; ++j) {
      mn = min(mn, h[i][j]);
    }
    for (int j = 1; j <= m; ++j) {
      h[i][j] -= mn;
    }
    for (int j = 0; j < mn; ++j) {
      c.push_back("row");
      d.push_back(i);
    }
  }

  int mini = 1e9 + 10;
  int rr = 1e9 + 10, cc = 1e9 + 10;

  int ya = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] != 0) {
        ya = 0;
        break;
      }
    }
    if (ya == 0) break;
  }
  if (ya) {
    rr = (int) a.size();
  }

  int yaa = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (h[i][j] != 0) {
        yaa = 0;
        break;
      }
    }
    if (yaa == 0) break;
  }
  if (yaa) {
    cc = (int) c.size();
  }

  mini = min(rr, cc);
  if (mini >= 1e8 + 10) {
    puts("-1");
    return 0;
  }

  if (rr < cc) {
    int sz = a.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++i) {
      printf("%s %d\n", a[i].c_str(), b[i]);
    }
  } else {
    int sz = c.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++i) {
      printf("%s %d\n", c[i].c_str(), d[i]);
    }
  }
  return 0;
}