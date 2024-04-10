#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
bitset <N> vis;
vector <pair <int, int>> e;

bool build (int nod, int edg) {
  if (!nod) return !edg;
  if (nod < 3) return 0;
  if (nod + 1 == edg) return 0;
  if (nod == edg) {
    for (int i = 1; i < nod; ++i) e.emplace_back(i, i + 1);
    e.emplace_back(1, nod);
    return 1;
  }
  int last = 3;
  for (int i = 3; i <= nod; ++i) {
    if (!vis[i - 1] and edg - i * (i - 1) / 2 >= nod - i) last = i;
  }
  // cout << nod << " " << edg << " " << last << endl;
  for (int i = nod - last + 1; i <= nod; ++i) {
    for (int j = i + 1; j <= nod; ++j) {
      e.emplace_back(i, j);
    }
  } 
  nod -= last, edg -= last * (last - 1) / 2;
  return build(nod, edg);
}

int main() {
  for (int i = 2; i * i < N; ++i) if (!vis[i]) {
    for (int j = i * i; j < N; j += i) vis[j] = 1;
  }
  cin >> n;
  if (n == 4) {
    cout << "5\n1 2\n1 3\n2 3\n2 4\n3 4\n";
    return 0;
  }
  if (n == 6) {
    cout << "7\n1 2\n2 3\n3 4\n4 5\n5 6\n6 1\n1 3\n";
    return 0;
  }
  if (n == 8) {
    cout << "13\n1 2\n1 3\n2 3\n1 4\n2 4\n1 5\n2 5\n1 6\n2 6\n1 7\n1 8\n5 8\n7 8\n";
    return 0;
  }
  if (n == 9) {
    cout << "11\n";
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    cout << "1 3\n6 8\n";
    return 0;
  }
  if (n == 10) {
    cout << "11\n";
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    cout << "1 3\n";
    return 0;
  }
  if (n == 12) {
    cout << "13\n";
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    cout << "1 3\n";
    return 0;
  }
  if (n == 14) {
    cout << "17\n";
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    cout << "1 3\n4 6\n7 9\n";
    return 0;
  }
  if (n == 15) {
    cout << "17\n";
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    cout << "1 3\n4 6\n";
    return 0;
  }
  if (n == 16) {
    cout << "17\n";
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    cout << "1 3\n";
    return 0;
  }
  if (!vis[n]) {
    cout << n << endl;
    for (int i = 1; i < n; ++i) cout << i << " " << i + 1 << '\n';
    cout << 1 << " " << n << '\n';
    return 0;
  }
  int m = n; 
  while (true) {
    while (vis[m]) ++m;
    e.clear();
    if (build(n, m)) {
      int sz = e.size();
      assert(sz <= n * (n - 1) / 2);
      cout << sz << '\n';
      for (auto it : e) cout << it.first << " " << it.second << '\n';
      return 0;
    } else ++m;
  }
  return 0;
}