#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct pt {
  int x, y, z, id;

  bool operator < (const pt &p) const {
    return x == p.x ? (y == p.y ? z < p.z : y < p.y) : x < p.x;
  }
};

int n; pt p[N]; vector <pt> rem;

void solve (vector <pt> &v) {
  vector <pt> yo;
  for (int i = 0; i < v.size();) {
    int j = i, k = i;
    while (j < v.size() and v[j].y == v[i].y) ++j;
    while (k + 1 < j) printf("%d %d\n", v[k].id, v[k + 1].id), k += 2;
    if (k < j) yo.emplace_back(v[k]);
    i = j;
  }
  for (int i = 0; i + 1 < yo.size(); i += 2) {
    printf("%d %d\n", yo[i].id, yo[i + 1].id);
  }
  if (yo.size() % 2) rem.emplace_back(yo.back()); 
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
    p[i].id = i;
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n;) {
    vector <pt> vec;
    int j = i;
    while (j <= n and p[i].x == p[j].x) vec.emplace_back(p[j++]);
    solve(vec); i = j;
  }
  assert(rem.size() % 2 == 0);
  for (int i = 0; i < rem.size(); i += 2) {
    printf("%d %d\n", rem[i].id, rem[i + 1].id);
  }
  return 0;
}