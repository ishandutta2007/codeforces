#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int M = 55;

string a[M];
string s;

int n, m;
vector<int> p = {0, 1, 2, 3};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cin >> s;
}

bool ok() {
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] == 'S')
        x = i, y = j;

  for (char c : s) {
    int nx = x + dx[p[c - '0']];
    int ny = y + dy[p[c - '0']];
    if (nx < 0 || ny < 0 ||
        nx >= n || ny >= m || a[nx][ny] == '#')
      return false;
    if (a[nx][ny] == 'E')
      return true;
    x = nx, y = ny;
  }
  return false;
}

void kill() {
  int ans = 0;
  for (int i = 0; i < 24; ++i) {
    if (ok())
      ++ans;
    next_permutation(all(p));
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("b.in", "r", stdin);
#endif

  read();
  kill();
    
  return 0;
}