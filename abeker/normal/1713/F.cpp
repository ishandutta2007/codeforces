#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> b;

void load() {
  scanf("%d", &N);
  b.resize(N);
  for (auto &it : b)
    scanf("%d", &it);
}

void sos(vector <int> &v) {
  for (int i = __builtin_ctz(v.size()) - 1; i >= 0; i--)
    for (int j = (int)v.size() - 1; j >= 0; j--)
      if (j >> i & 1)
        v[j] ^= v[j ^ 1 << i];
}

void invert(vector <int> &v) {
  if (v.size() <= 1)
    return;
  int n = v.size(), pot = 1;
  while (pot < n)
    pot *= 2;
  vector <int> u = v;
  u.resize(pot);
  reverse(u.begin(), u.end());
  vector <int> w = u;
  sos(u);
  reverse(u.begin(), u.end());
  u.resize(pot - n);
  invert(u);
  for (int i = 0; i < pot - n; i++)
    w[i] = u[i];
  sos(w);
  w.resize(n);
  v = w;
}

void solve() {
  invert(b);
  reverse(b.begin(), b.end());
  for (auto it : b)
    printf("%d ", it);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}