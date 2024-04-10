#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int M = N+6;
int bit[M];

vector<int> add_pts[M], sub_pts[M];
int L[M], R[M];

void add(int i, int x) {
  for (; i < M; i += i&-i) bit[i] += x;
}

int query(int i) {
  int ans = 0;
  for (; i > 0; i -= i&-i) ans += bit[i];
  return ans;
}

struct seg {
  int y, l, r;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<seg> horizontal(n), vertical(m);
  for (auto& [y, l, r]: horizontal) cin >> y >> l >> r;
  for (auto& [y, l, r]: vertical) cin >> y >> l >> r;
  horizontal.emplace_back(seg{0, 0, N});
  horizontal.emplace_back(seg{N, 0, N});
  vertical.emplace_back(seg{0, 0, N});
  vertical.emplace_back(seg{N, 0, N});
  auto calc = [&] () {
    for (int i = 0; i <= N; i++) {
      L[i] = R[i] = -1;
      add_pts[i].clear();
      sub_pts[i].clear();
    }
    for (auto& [y, l, r]: horizontal) {
      L[y] = l;
      R[y] = r;
    }
    for (auto& [y, l, r]: vertical) {
      add_pts[l].emplace_back(y);
      sub_pts[r].emplace_back(y);
    }

    long long v = 0, e = 0;
    for (int i = 0; i <= N; i++) {
      for (int y: add_pts[i]) {
        add(y+1, 1);
      }
      if (L[i] != -1) {
        int k = query(R[i]+1)-query(L[i]);
        v += k;
        e += k-1;
      }
      for (int y: sub_pts[i]) {
        add(y+1, -1);
      }
    }
    return make_pair(v, e);
  };

  long long v, e;
  tie(v, e) = calc();
  swap(horizontal, vertical);
  e += calc().second;
  cout << e-v+1 << '\n';
}