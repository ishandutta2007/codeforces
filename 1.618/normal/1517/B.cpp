/*


Q.E.D.
*/
/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 105
#define mp make_pair
typedef pair<int, int> P;
typedef pair<int, P> PiP;

int n, m, b[maxn][maxn], c[maxn][maxn];
vector<PiP> paths;

void solve() {
  memset(c, 0, sizeof(c));
  paths.clear();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &b[i][j]);
      paths.push_back(mp(b[i][j], mp(i, j)));
    }
  }
  sort(paths.begin(), paths.end());
  for (int i = 0; i < m; i++)
    c[paths[i].second.first][paths[i].second.second] = i + 1;
    
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= m; j++) {
//      cout << c[i][j] << " ";
//    }
//    cout << endl;
//  }
//  system("pause");
  
  for (int i = 1; i <= n; i++) {
    vector<int> foo;
    for (int j = 1; j <= m; j++) {
      bool app = false;
      for (int k = 1; k <= m; k++) {
        if (c[i][k] == j)
          app = true;
      }
      if (!app)
        foo.push_back(j);
    }
    for (int j = 1; j <= m; j++) {
      if (!c[i][j]) {
        c[i][j] = foo.back();
        foo.pop_back();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int res;
      for (int k = 1; k <= m; k++) {
        if (c[i][k] == j)
          res = b[i][k];
      }
      printf("%d%c", res, j == m ? '\n' : ' ');
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}