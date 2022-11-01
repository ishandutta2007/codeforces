#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 1010;

int n; ll a[N], x[N];
vector <int> ans;

inline int nxt (int j, int k) {
  return j + 1 == k ? 0 : j + 1;
}

bool good (int k) {
  for (int i = 0; i < k; ++i) {
    x[i] = a[i + 1] - a[i];
  }
  ll cur = 0;
  for (int i = 1, j = 0; i <= n; ++i, j = nxt(j, k)) {
    cur += x[j];
    if (a[i] != cur) return 0;
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    if (good(i)) ans.push_back(i);
  }
  int sz = ans.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; ++i) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}