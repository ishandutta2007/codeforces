#include <bits/stdc++.h>

using namespace std;

const int N = 3050;
const int M = 10000010;
const int MOD = 1e9 + 7;

int n, m, f[N], tr[M][2], ptr;
string s = "#";

void insert() {
  int u = 0;
  for (int i = n; i >= 1; --i) {
    int cur = s[i] - '0';
    int &nxt = tr[u][cur];
    if (nxt == -1) nxt = ++ptr;
    u = nxt;
  }
}

int search() {
  int u = 0;
  for (int i = n; i >= 1; --i) {
    int cur = s[i] - '0';
    int &nxt = tr[u][cur];
    if (nxt == -1) return i;
    u = nxt;
  }
  return 0;
}

int get (int lim) {
  // lim.....n
  if (lim > n) return 1;
  for (int i = 0; i < lim; ++i) f[i] = 1;
  for (int i = lim; i <= n; ++i) {
    f[i] = 1;
    for (int j = 1; j <= 4; ++j) {
      if (i - j < lim - 1) continue;
      string yo = s.substr(i - j + 1, j);
      if (yo == "0011" or yo == "0101" or yo == "1110" or yo == "1111") continue;
      f[i] += f[i - j];
      if (f[i] >= MOD) f[i] -= MOD;
    }
  }
  return f[n];
}

int main() {
  memset(tr, -1, sizeof tr);
  cin >> m;
  f[0] = 1; int ans = 0;
  while (m--) {
    char c; cin >> c; s += c; ++n;
    int pos = search();
    // cout << pos << " ----\n";
    // cout << " ---> " << get(1) << endl;
    // cout << get(1) << " " << get(pos + 1) << endl;
    int add = get(1) - get(pos + 1);
    if (add < 0) add += MOD;
    ans += add;
    if (ans >= MOD) ans -= MOD;
    cout << ans << '\n';
    insert();
  }
  return 0;
}