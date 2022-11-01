#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, a[N], t[N << 1];
map <int, vector <int>> pos;

int get (int l, int r) {
  int ret = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = max(ret, t[l++]);
    if (r & 1) ret = max(ret, t[--r]);
  }
  return ret;
}

void fuck (int l, int r, bool flag = 1) {
  if (l > r) return;
  int curMax = get(l, r + 1), m = pos[curMax].size();
  int st = lower_bound(pos[curMax].begin(), pos[curMax].end(), l) - pos[curMax].begin();
  int en = upper_bound(pos[curMax].begin(), pos[curMax].end(), r) - pos[curMax].begin();
  if (flag and (en - st) & 1) {
    cout << "NO\n";
    exit(0);
  }
  fuck(l, pos[curMax][st] - 1);
  for (int i = st; i + 1 < en; ++i) fuck(pos[curMax][i] + 1, pos[curMax][i + 1] - 1);
  fuck(pos[curMax][en - 1] + 1, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    t[n + i] = a[i];
    pos[a[i]].emplace_back(i);
  }
  for (int i = n - 1; i; --i) {
    t[i] = max(t[i << 1], t[i << 1 | 1]);
  }
  fuck(0, n - 1, 0); cout << "YES\n";
  return 0;
}


// 3 1 1 3 4 5