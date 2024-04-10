#include <bits/stdc++.h>
using namespace std;

const int N = 8008;

int n;
char s[N];
int deg[N];
bitset<N> G[N];
vector<int> S, P, Q;
int inP[N], inQ[N];

long long ans;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0, x; j < n; j += 4) {
      x = s[j >> 2] - '0';
      (x > 9) && (x -= 7);
      G[i][j] = (x >> 3) & 1;
      G[i][j + 1] = (x >> 2) & 1;
      G[i][j + 2] = (x >> 1) & 1;
      G[i][j + 3] = x & 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (G[i].test(j)) {
        deg[j]++;
      }
    }
  }
  int m = n;
  {
    queue<int> Q;
    for (int i = 0; i < n; i++) {
      if (!deg[i]) {
        Q.push(i);
      }
    }
    const long long coef = 614 * n + 1;
    while (!Q.empty()) {
      int p = Q.front();
      Q.pop();
      ans += --m * coef;
      for (int i = 0; i < n; i++) {
        if (G[p].test(i) && !--deg[i]) {
          Q.push(i);
        }
      }
    }
  }
  if (!m) {
    printf("%lld\n", ans);
    return 0;
  }
  assert(m >= 3);
  S.reserve(m);
  for (int i = 0; i < n; i++) {
    if (deg[i]) {
      S.push_back(i);
    }
  }
  int X = S[0];
  for (auto p : S) {
    if (deg[p] > deg[X]) {
      X = p;
    }
  }
  for (auto p : S) {
    if (p == X || G[p].test(X)) {
      P.push_back(p);
    } else {
      Q.push_back(p);
    }
  }
  for (auto p : P) {
    for (int q : S) {
      if (G[p].test(q)) {
        inP[q]++;
      }
    }
  }
  for (auto p : Q) {
    for (int q : S) {
      if (G[p].test(q)) {
        inQ[q]++;
      }
    }
  }
  sort(P.begin(), P.end(), [&] (int x, int y) { return G[y].test(x); });
  sort(Q.begin(), Q.end(), [&] (int x, int y) { return G[y].test(x); });
  ans += 3ll * m * (m - 1) / 2;
  for (int i = 0, t = P.size(); i < t; i++) {
    for (int j = i + 1; j < t; j++) {
      ans += (inQ[P[i]] == inQ[P[j]]);
    }
  }
  for (int i = 0, t = Q.size(); i < t; i++) {
    for (int j = i + 1; j < t; j++) {
      ans += (inP[Q[i]] == inP[Q[j]]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}