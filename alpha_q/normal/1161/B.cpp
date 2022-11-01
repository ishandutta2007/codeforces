#include <bits/stdc++.h>

using namespace std;

typedef vector <int> VI;

const int N = 400010;

int n, m;
VI t[N], p[N];

void buildPi (VI &pi) {
  pi = VI(n);
  int k = -2;
  for (int i = 0; i < n; ++i) {
    while (k >= -1 && p[k + 1] != p[i])
      k = (k == -1) ? -2 : pi[k];
    pi[i] = ++k;
  }
}

bool KMP() {
  VI pi;
  buildPi(pi);
  int k = -1;
  for (int i = 0; i < n + n; ++i) {
    while (k >= -1 && p[k + 1] != t[i])
      k = (k == -1) ? -2 : pi[k];
    ++k;
    if (k == n - 1) {
      if (i - k > 0 and i - k < n) return 1;
      k = (k == -1) ? -2 : pi[k];
    }
  }
  return 0;
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    p[u].emplace_back((v - u + n) % n);
    p[v].emplace_back((u - v + n) % n);
  }
  for (int i = 0; i < n; ++i) {
    sort(p[i].begin(), p[i].end());
    t[i] = t[n + i] = p[i];
  }
  cout << (KMP() ? "Yes" : "No") << endl;
  return 0;
}