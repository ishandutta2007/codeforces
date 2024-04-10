#include <bits/stdc++.h>

using namespace std;

const int N = 2069;

bitset <N> vis[N];
int n, ans[N][N], p[N];

inline int ask (int i, int j) {
  if (i == j) return -1;
  if (i > j) swap(i, j);
  if (!vis[i][j]) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    cin >> ans[i][j]; vis[i][j] = 1;
  }
  return ans[i][j];
}

int main() {
  cin >> n;
  vector <int> zero = {0, 1};
  for (int i = 2; i < n; ++i) {
    zero.emplace_back(i);
    int out = -1, x = ask(zero[0], zero[1]), y = ask(zero[0], zero[2]);
    if (x < y) out = 2; 
    else if (x > y) out = 1;
    else out = 0;
    zero.erase(zero.begin() + out);
  }
  while (zero.size() > 1) {
    int x = rand() % n;
    if (x != zero[0] and x != zero[1] and ask(x, zero[0]) != ask(x, zero[1])) {
      if (ask(x, zero[0]) > ask(x, zero[1])) {
        zero.erase(zero.begin());
      } else {
        zero.erase(zero.begin() + 1);
      }
      break;
    }
  }
  assert(zero.size() == 1);
  int pos = zero[0];
  for (int i = 0; i < n; ++i) {
    p[i] = ((i == pos) ? 0 : ask(i, pos));
  }
  cout << "!";
  for (int i = 0; i < n; ++i) cout << " " << p[i];
  cout << endl;
  return 0;
}