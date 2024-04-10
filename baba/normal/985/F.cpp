#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int BASE = 2;
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a = a + b;
  if (a >= MOD) a -= MOD;
  return a;
}
int sub(int a, int b) {
  a = a - b;
  if (a < 0) a += MOD;
  return a;
}
int mul(int a, int b) { return (a * 1ll * b) % MOD; }
int power(int a, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = mul(ret, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ret;
}

int H[26][N], mp[N][26], pw[N], inv[N], pos[26];
char s[N];

int getHash(int i, int l, int r) {
  return mul(sub(H[i][r], H[i][l - 1]), inv[l]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  pw[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = mul(pw[i - 1], BASE);
    inv[i] = power(pw[i], MOD - 2);
  }
  for (int c = 0; c < 26; c++) {
    for (int i = 1; i <= n; i++) {
      H[c][i] = add(H[c][i - 1], (s[i] == c + 'a') * pw[i]);
    }
  }
  for (int i = 0; i < 26; i++) {
    pos[i] = n + 1;
  }
  for (int i = n; i >= 1; i--) {
    pos[s[i] - 'a'] = i;
    vector<pair<int, int>> temp;
    for (int c = 0; c < 26; c++) {
      temp.push_back(make_pair(pos[c], c));
    }
    sort(temp.begin(), temp.end());
    for (int c = 0; c < 26; c++) {
      mp[i][c] = temp[c].second;
    }
  }
  while (m--) {
    int x, y, len;
    scanf("%d %d %d", &x, &y, &len);
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      ok &= getHash(mp[x][i], x, x + len - 1) ==
            getHash(mp[y][i], y, y + len - 1);
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}