#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> ext[N];
vector <pair <int, int>> e;
int n, m, ptr, a[N], d[N], id[N];

void AddEdge (int u, int v) {
  if (u > v) swap(u, v);
  if (!u or !v) return;
  e.emplace_back(u, v);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", d + i), id[i] = i;
  sort(id + 1, id + n + 1, [] (int i, int j) {return d[i] > d[j];});
  int f = id[1], it;
  if (d[f] == 1) {
    for (int i = 1; i < n + n; ++i) {
      printf("%d %d\n", i, i + 1);
    }
    return 0;
  }
  a[1] = f + f - 1, a[1 + d[f]] = f + f;
  ptr = 2, m = 1 + d[f];
  int gap = d[f] - 1;
  for (it = 2; it <= n; ++it) {
    int i = id[it];
    if (d[i] == 1) break;
    if (gap) {
      while (a[ptr]) ++ptr;
      a[ptr] = i + i - 1; --gap;
      if (ptr + d[i] == m + 1) {
        a[++m] = i + i; 
      } else if (!a[ptr + d[i]]) {
        a[ptr + d[i]] = i + i; --gap;
      } else {
        ext[ptr + d[i] - 1].emplace_back(i + i);
      }
    } else {
      ext[1].emplace_back(i + i - 1);
      ext[d[i] - 1].emplace_back(i + i);
    }
  }
  while (it <= n) {
    int i = id[it];
    if (gap) {
      while (a[ptr]) ++ptr;
      a[ptr] = i + i - 1; --gap;
      if (!a[ptr + 1]) {
        a[ptr + 1] = i + i; --gap;
      } else {
        ext[ptr].emplace_back(i + i);
      }
    } else {
      a[m + 1] = i + i - 1, a[m + 2] = i + i;
      m += 2;
    }
    ++it;
  }
  for (int i = 1; i < m; ++i) AddEdge(a[i], a[i + 1]);
  for (int i = 1; i <= m; ++i) for (int j : ext[i]) AddEdge(a[i], j);
  sort(e.begin(), e.end());
  e.erase(unique(e.begin(), e.end()), e.end());
  for (auto it : e) printf("%d %d\n", it.first, it.second);
  return 0;
}


// 5 5 5 5 5 6
// 1 - 3 - 5 - 7 - 9 - O - 2 - 6 - 8 - 11
//                     |   
//                     4