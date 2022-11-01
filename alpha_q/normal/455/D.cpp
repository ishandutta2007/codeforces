#include <bits/stdc++.h>

using namespace std;

const int B = 320;
const int N = 100010;

vector <int> b[B];
int n, q, a[N], f[B][N];

int get (int x, int &at, int &pos) {
  int sum = 0; at = 0;
  while (sum + b[at].size() <= x) sum += b[at++].size();
  pos = x - sum;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    ++f[i / B][a[i]];
    b[i / B].push_back(a[i]);
  }
  cin >> q;
  int last = 0;
  for (int it = 0; it < q; ++it) {
    if (it % B == 0) {
      for (int i = 0, k = 0; i < B; ++i) {
        for (int j : b[i]) --f[i][j], a[k++] = j;
        b[i].clear();
      }
      for (int i = 0; i < n; ++i) {
        ++f[i / B][a[i]];
        b[i / B].push_back(a[i]);
      }
    }
    int cmd, l, r, k;
    scanf("%d %d %d", &cmd, &l, &r);
    l = (l + last - 1) % n;
    r = (r + last - 1) % n;
    if (l > r) swap(l, r);
    if (cmd == 1) {
      int l_at, l_pos, r_at, r_pos;
      get(l, l_at, l_pos);
      get(r, r_at, r_pos);
      int x = b[r_at][r_pos];
      --f[r_at][x], ++f[l_at][x];
      b[r_at].erase(b[r_at].begin() + r_pos);
      b[l_at].insert(b[l_at].begin() + l_pos, x);
    } else {
      scanf("%d", &k);
      k = (k + last - 1) % n + 1;
      int l_at, l_pos, r_at, r_pos;
      get(l, l_at, l_pos);
      get(r, r_at, r_pos);
      last = 0;
      if (l_at == r_at) {
        for (int i = l_pos; i <= r_pos; ++i) last += b[l_at][i] == k;
      } else {
        for (int i = l_pos; i < b[l_at].size(); ++i) last += b[l_at][i] == k;
        for (int i = 0; i <= r_pos; ++i) last += b[r_at][i] == k;
        for (int i = l_at + 1; i < r_at; ++i) last += f[i][k];
      }
      printf("%d\n", last);
    }
  }
  return 0;
}