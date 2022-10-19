#include <bits/stdc++.h>

using namespace std;

const int M = 505;

int n, m;
bool a[M][M];
int c[M];
char s[M];
bool used[M];
vector<int> g[M];

void dfs(int v, int col) {
  c[v] = col;
  used[v] = true;

  for (int to : g[v])
    if (!used[to])
      dfs(to, 1 - col);
}


void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    a[u][v] = a[v][u] = true;
  }
}

bool good(char x, char y) {
  if (x > y)
    swap(x, y);
  return x == 'a' && y == 'c';
}

void kill() {
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (!a[i][j]) {
        g[i].push_back(j);
        g[j].push_back(i);
      } 

  fill(c, c + M, 2);

  for (int i = 0; i < n; ++i)
    if (!used[i] && !g[i].empty()) {
      dfs(i, 0);
    }


  for (int i = 0; i < n; ++i) {
    if (c[i] == 2)
      s[i] = 'b';
    else if (c[i] == 1)
      s[i] = 'a';
    else
      s[i] = 'c';
  }

  bool ans = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j)
        if ((!a[i][j] && !good(s[i], s[j])) || (a[i][j] && good(s[i], s[j])))
          ans = false;

  if (!ans)
    cout << "No\n";
  else {
    cout << "Yes\n";
    cout << (string(s, s + n)) << endl;
  }

}


int main() {
  read();
  kill();
}