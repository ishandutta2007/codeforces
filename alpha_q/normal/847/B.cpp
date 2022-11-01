#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int INF = 1e9 + 5;

vector <int> v[N];
int n, ptr, a[N], t[N + N];

void update (int p, int v) {
  for (t[p += n] = v; p > 1; p >>= 1) {
    t[p >> 1] = min(t[p], t[p ^ 1]);
  }
}

int query (int l, int r) {
  int ret = INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = min(ret, t[l++]);
    if (r & 1) ret = min(ret, t[--r]);
  }
  return ret;
}

int findFirst (int x) {
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (query(0, mid) < x) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i); 
    int first = findFirst(a[i]);
    v[first].push_back(a[i]);
    update(first - 1, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (v[i].empty()) {
      break;
    }
    for (int x : v[i]) {
      printf("%d ", x);
    }
    puts("");
  }
  return 0;
}