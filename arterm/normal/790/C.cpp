#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 80;
const int inf = 1e9;

int n;
string s;
vector<int> pos[3];
int d[M][M][M][3];

int dec(char c) {
  if (c == 'V')
    return 0;
  else if (c == 'K')
    return 1;
  else
    return 2;
}

void read() {
  cin >> n;
  cin >> s;
}

int uin(int &x, int y) {
  return x = min(x, y);
}

int mabs(int x) {
  return x < 0 ? -x : x;
}

int price(int t, int i, int x) {
  int cnt = lower_bound(pos[t].begin(), pos[t].begin() + i, x) - pos[t].begin();
  return i - cnt;
}

int cost(int i, int j, int k, int x) {
  return price(0, i, x) + 
    price(1, j, x) +
    price(2, k, x);
}

void kill() {
  for (int i = 0; i < n; ++i) {
    pos[dec(s[i])].push_back(i);
  }

  for (int i = 0; i < M; ++i)
    for (int j = 0; j < M; ++j)
      for (int k = 0; k < M; ++k)
        for (int t = 0; t < 3; ++t)
          d[i][j][k][t] = inf;

  d[0][0][0][2] = 0;

  for (int i = 0; i <= (int) pos[0].size(); ++i)
    for (int j = 0; j <= (int) pos[1].size(); ++j)
      for (int k = 0; k <= (int) pos[2].size(); ++k)
        for (int last = 0; last <= 2; ++last) {
          int cur = d[i][j][k][last];
          if (cur == inf)
            continue;

          if (i < (int) pos[0].size()) {
            uin(d[i + 1][j][k][0], cur + cost(i, j, k, pos[0][i]));
          }

          if (j < (int) pos[1].size() && last != 0) {
            uin(d[i][j + 1][k][1], cur + cost(i, j, k, pos[1][j]));
          }

          if (k < (int) pos[2].size()) {
            uin(d[i][j][k + 1][2], cur + cost(i, j, k, pos[2][k]));
          }
        }
  
  int ans = inf;
  for (int last = 0; last <= 2; ++last)
    uin(ans, d[pos[0].size()][pos[1].size()][pos[2].size()][last]);
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}